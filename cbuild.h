#ifndef CBUILD_H
#define CBUILD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h> // Ensure you have the json-c library installed

typedef struct {
    char *name;
    char *source_file;
    char *build_mode;  // "debug", "release", or "testing"
} Target;

typedef struct {
    Target *targets;
    int target_count;
} CBuildConfig;

CBuildConfig load_config(const char *filename) {
    CBuildConfig config = {0};
    struct json_object *parsed_json;
    struct json_object *targets_json;
    size_t target_count;

    // Load and parse the JSON file
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open config file");
        return config;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *data = malloc(length + 1);
    fread(data, 1, length, file);
    fclose(file);
    data[length] = '\0';

    parsed_json = json_tokener_parse(data);
    json_object_object_get_ex(parsed_json, "targets", &targets_json);
    target_count = json_object_array_length(targets_json);
    
    // Allocate memory for targets
    config.targets = malloc(sizeof(Target) * target_count);
    config.target_count = target_count;

    for (size_t i = 0; i < target_count; i++) {
        struct json_object *target_json = json_object_array_get_idx(targets_json, i);
        struct json_object *name_json;
        struct json_object *source_file_json;
        struct json_object *build_mode_json;

        json_object_object_get_ex(target_json, "name", &name_json);
        json_object_object_get_ex(target_json, "source_file", &source_file_json);
        json_object_object_get_ex(target_json, "build_mode", &build_mode_json);

        config.targets[i].name = strdup(json_object_get_string(name_json));
        config.targets[i].source_file = strdup(json_object_get_string(source_file_json));
        config.targets[i].build_mode = strdup(json_object_get_string(build_mode_json));
    }
    
    free(data);
    return config;
}

void run_command(const char *command) {
    printf("Running command: %s\n", command);
    int result = system(command);
    if (result == -1) {
        perror("Error executing command");
    }
}

void build_target(Target target) {
    char build_command[512];
    char executable_name[512];

    // Check the operating system and compiler being used
#ifdef _WIN32
    #ifdef _MSC_VER
    // MSVC
    if (strcmp(target.build_mode, "release") == 0) {
        snprintf(executable_name, sizeof(executable_name), "%s.exe", target.name);
    } else {
        snprintf(executable_name, sizeof(executable_name), "%s", target.name);
    }
    snprintf(build_command, sizeof(build_command), "cl /EHsc /Fe:%s %s", executable_name, target.source_file);
    #elif defined(__MINGW32__) || defined(__MINGW64__)
    // MinGW
    if (strcmp(target.build_mode, "debug") == 0) {
        snprintf(build_command, sizeof(build_command), "gcc -g %s -o %s", target.source_file, target.name);
    } else if (strcmp(target.build_mode, "release") == 0) {
        snprintf(build_command, sizeof(build_command), "gcc -O2 %s -o %s.exe", target.source_file, target.name);
    } else if (strcmp(target.build_mode, "testing") == 0) {
        snprintf(build_command, sizeof(build_command), "gcc -g -DTESTING %s -o %s", target.source_file, target.name);
    } else {
        fprintf(stderr, "Unknown build mode: %s\n", target.build_mode);
        return;
    }
    #else
    // Unsupported Windows compiler
    fprintf(stderr, "Unsupported Windows compiler.\n");
    return;
    #endif

#elif defined(__linux__)
    // Linux
    if (strcmp(target.build_mode, "debug") == 0) {
        snprintf(build_command, sizeof(build_command), "gcc -g %s -o %s", target.source_file, target.name);
    } else if (strcmp(target.build_mode, "release") == 0) {
        snprintf(build_command, sizeof(build_command), "gcc -O2 %s -o %s.exe", target.source_file, target.name);
    } else if (strcmp(target.build_mode, "testing") == 0) {
        snprintf(build_command, sizeof(build_command), "gcc -g -DTESTING %s -o %s", target.source_file, target.name);
    } else {
        fprintf(stderr, "Unknown build mode: %s\n", target.build_mode);
        return;
    }
#else
    // Other platforms (optional)
    fprintf(stderr, "Unsupported platform.\n");
    return;
#endif

    // Run the build command
    run_command(build_command);
}

void free_config(CBuildConfig config) {
    for (int i = 0; i < config.target_count; i++) {
        free(config.targets[i].name);
        free(config.targets[i].source_file);
        free(config.targets[i].build_mode);
    }
    free(config.targets);
}

#endif // CBUILD_H
