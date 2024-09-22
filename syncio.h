#ifndef SYNCIO_H
#define SYNCIO_H

#include <stdlib.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

#ifdef __cplusplus
namespace Syncio {
    template <typename T>
    void TypeLine(const T& value) {
        std::cout << value << std::endl;
    }
}
#else
#include <stdio.h>
#include <stdbool.h>
FILE* fload(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);

    if (ferror(file) || file == NULL) {
        perror("Error: Cound not open file\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    return file;
}
#endif

#endif // SYNCIO_H