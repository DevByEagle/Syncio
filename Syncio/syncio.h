#ifndef SYNCIO_H
#define SYNCIO_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

#ifdef __cplusplus
namespace Syncio {

}
#else
FILE* fload(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);

    if (ferror(file) || file == NULL) {
        exit(EXIT_FAILURE);
    }
    return file;
}
#endif

#endif // SYNCIO_H