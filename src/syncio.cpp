#include <cstdio>
#include <cstdarg>
#include <unistd.h>

#include "../include/syncio.h"

void println(const char* format, ...) {
    std::va_list args;
    va_start(args, format);

    std::vprintf(format, args);

    va_end(args);
}

void raise(const char* format, ...) {
    std::va_list args;
    va_start(args, format);
    
    std::vfprintf(stdout, format, args);

    va_end(args);
}

void delay(unsigned int second) {
    sleep(second);
}