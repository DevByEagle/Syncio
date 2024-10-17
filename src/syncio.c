#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#include "../include/syncio.h"

void println(const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    vprintf(format, args);

    va_end(args);
}

void raise(const char* format, ...) {
    va_list args;
    va_start(args, format);

    vfprintf(stdout, format, args);

    va_end(args);
}