#include <cstdio>
#include <cstdarg>
#include <iostream>
#include <string>
#include <unistd.h>

#include "../include/syncio.h"

void Syncio::println(Syncio::string format, ...)
{
    std::va_list args;
    va_start(args, format);

    std::vprintf(format.c_str(), args);

    va_end(args);
}

void Syncio::raise(Syncio::string format, ...)
{
    std::va_list args;
    va_start(args, format);

    std::vfprintf(stdout, format.c_str(), args);

    va_end(args);
}