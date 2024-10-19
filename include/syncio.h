#ifndef SYNCIO_H
#define SYNCIO_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Outputs a message to the console and appends a newline for better readability. */
void println(const char* format, ...);

 /** @brief Triggers an error, throwing an exception or terminating the program with a specified message. */
void raise(const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif //SYNCIO_H