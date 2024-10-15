#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "../include/syncio.h"

void delay(unsigned int ms) {
    sleep(ms);
}

void println(string format, ...) {
 va_list args;
 va_start(args, format);
 vprintf(format, args);
 va_end(args);   
}

void raise(string format, ...) {
    va_list args;
    va_start(args, format);
    
    vfprintf(stdout, format, args);

    va_end(args);
}

char* input(string prompt) {
    // Print the prompt
    printf("%s", prompt);

    // Allocate an initial buffer
    Size_t buffer_size = 64;
    char* buffer = malloc(buffer_size);
    if (!buffer) {
        return NULL; // Handle allocation failure
    }

    Size_t length = 0;
    int ch;

    // Read input character by character
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (length + 1 >= buffer_size) {
            // Resize buffer if needed
            buffer_size *= 2;
            char* new_buffer = realloc(buffer, buffer_size);
            if (!new_buffer) {
                free(buffer); // Free the previous buffer
                return NULL;
            }
            buffer = new_buffer;
        }
        buffer[length++] = (char)ch;
    }

    buffer[length] = '\0'; // Null-terminate the string

    return buffer;
}