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
    char* tostring(int num) {
        char* str = (char*)malloc(12 * sizeof(char));
        if (str == NULL) {
            return NULL; // Handle memory allocation failure
        }

        sprintf(str, "%d", num);
        return str;
    }
    int tonumber(const char* str) { return atoi(str); }
}
#else
char* tostring(int num) {
     char* str = (char*)malloc(12 * sizeof(char));
        if (str == NULL) {
            return NULL; // Handle memory allocation failure
        }

        sprintf(str, "%d", num);
        return str;
}
int tonumber(const char* str) { return atoi(str); }
#endif

#endif // SYNCIO_H