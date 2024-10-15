#include <stdio.h>
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

/*int raise(FILE* stream, string format, ...) {
    va_list args;
    int written;

    va_start(args, format);

    written = vfprintf(stream, format, args);

    va_end(args);

    return written;
}*/
