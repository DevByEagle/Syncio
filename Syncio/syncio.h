#ifndef SYNCIO_H
#define SYNCIO_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

#define ASSERT(expr, ...)                                 \
    do {                                                         \
        if (!(expr)) {                                            \
            printf("Assertion failed: ");                         \
            printf(__VA_ARGS__);                                  \
            printf("\n"); \
            exit(EXIT_FAILURE);                                   \
        }                                                        \
    } while (0)

#ifdef __cplusplus
namespace Syncio {

}
#else
char* fload(const char* filename, size_t* outSize) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    // Seek to the end of the file to determine the size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET); // Go back to the beginning

    // Allocate memory for the file contents
    char* buffer = (char*)malloc(fileSize + 1); // +1 for null terminator
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    // Read the file into the buffer
    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Failed to read file");
        free(buffer);
        fclose(file);
        return NULL;
    }

    buffer[bytesRead] = '\0'; // Null-terminate the string
    fclose(file);

    if (outSize) {
        *outSize = bytesRead; // Return the size if requested
    }
    
    return buffer;
}
#endif

#endif // SYNCIO_H