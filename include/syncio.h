#ifndef SYNCIO_H
#define SYNCIO_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Outputs a message to the console and appends a newline for better readability. */
void println(const char* format, ...);

void raise(const char* format, ...);

void delay(unsigned int seconds);

#ifdef __cplusplus
}
#endif

#endif // SYNCIO_H
