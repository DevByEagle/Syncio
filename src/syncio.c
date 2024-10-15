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

    for (const char *p = format; *p != '\0'; p++) {
        if (*p == '%' && *(p + 1) != '\0') {
            p++;
            switch (*p) {
                case 'd': { // integer
                    int i = va_arg(args, int);
                    printf("%d", i);
                    break;
                }
                case 's': { // string
                    char *s = va_arg(args, char *);
                    printf("%s", s);
                    break;
                }
                default:   // unsupported format
                    printf("%%");
                    printf("%c", *p);
                    break;
            }
        } else {
            putchar(*p); // print regular character
        }
    }

    va_end(args);   
}