#ifndef SYNCIO_H
#define SYNCIO_H

#include "types.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <unistd.h>
#endif

#ifdef __cplusplus
#include <iostream>
namespace Syncio {
    void delay(int ms) {
        #if defined(_WIN32) || defined(_WIN64)
            Sleep(ms);
        #else
            usleep(ms * 1000);
        #endif
    }
}
#else
#include <stdio.h>

void delay(int ms) {
#if defined (_WIN32) || defined(_WIN64)
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}
#endif

#endif // SYNCIO_H