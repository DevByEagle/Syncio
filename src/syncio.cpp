#include <cstdio>
#include <cstdarg>
#include <string>
#include <unistd.h>

#include "../include/syncio.h"

void Syncio::println(Syncio::string format, ...) {
    std::va_list args;
    va_start(args, format);

    std::vprintf(format, args);

    va_end(args);
}

void Syncio::raise(Syncio::string format, ...) {
    std::va_list args;
    va_start(args, format);
    
    std::vfprintf(stdout, format, args);

    va_end(args);
}