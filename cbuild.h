#ifndef CBUILD_H
#define CBUILD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// Detect OS
#if defined(_WIN32) || defined(_WIN64)
    #define CBUILD_OS_WINDOWS 1
#else
    #define CBUILD_OS_LINUX 1
#endif

// Build settings structure
typedef struct {
    const char **source_files;
    size_t num_files;
    const char *output_name;
    const char *compiler;
    const char *flags;
    const char *libs;
} CBuildConfig;

// Default build settings
static CBuildConfig cbuild_default_config(const char **source_files, size_t num_files, const char *output_name) {
    CBuildConfig config;
    config.source_files = source_files;
    config.num_files = num_files;
    config.output_name = output_name;

    #if CBUILD_OS_WINDOWS
    config.compiler = "cl"; // MSVC compiler
    config.flags = "/EHsc";
    config.libs = "";
    #else
    config.compiler = "gcc"; // GCC for Linux
    config.flags = "-Wall -O2"; // Enable warnings and optimizations
    config.libs = "";
    #endif

    return config;
}

static void cbuild_add_flags(CBuildConfig *config, ...) {
    size_t current_length = strlen(config->flags);
    
    // Initialize va_list to handle variable arguments
    va_list args;
    va_start(args, config);

    // Calculate the total length of all new flags
    size_t new_length = current_length;
    const char *flag = va_arg(args, const char*);
    while (flag != NULL) {
        new_length += strlen(flag) + 1; // +1 for the space separator
        flag = va_arg(args, const char*);
    }
    va_end(args);

    // Allocate memory for the new flags
    char *new_flags = (char*)malloc(new_length + 1);
    snprintf(new_flags, new_length + 1, "%s", config->flags);

    // Add each new flag to the configuration
    va_start(args, config);
    flag = va_arg(args, const char*);
    while (flag != NULL) {
        strncat(new_flags, " ", new_length - strlen(new_flags));
        strncat(new_flags, flag, new_length - strlen(new_flags));
        flag = va_arg(args, const char*);
    }
    va_end(args);

    // Set the new flags in the configuration
    config->flags = new_flags;
}

static void cbuild_add_libs(CBuildConfig *config, const char *libs) {
    size_t current_length = strlen(config->libs);
    size_t new_length = current_length + strlen(libs) + 1;

    char *new_libs = (char*)malloc(new_length);
    snprintf(new_libs, new_length, "%s %s", config->libs, libs);

    config->libs = new_libs;
}

// Build the project
static void cbuild_run(const CBuildConfig *config) {
    char command[1024] = {0};

    // Prepare compiler and flags
    snprintf(command, sizeof(command), "%s %s -o %s", config->compiler, config->flags, config->output_name);

    // Add source files
    for (size_t i = 0; i < config->num_files; i++) {
        snprintf(command + strlen(command), sizeof(command) - strlen(command), " %s", config->source_files[i]);
    }

    // Add libraries if any
    if (strlen(config->libs) > 0) {
        snprintf(command + strlen(command), sizeof(command) - strlen(command), " %s", config->libs);
    }

    // Execute the command
    int result = system(command);
    if (result == 0) {
        printf("[INFO] Build Successful: %s\n", config->output_name);
    } else {
        printf("[ERROR] Build failed with error code: %d\n", result);
    }
}

static void cbuild_cleanup(CBuildConfig *config) {
    free((void *)config->flags);
    free((void *)config->libs);
}

#endif // CBUILD_H