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