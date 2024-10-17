/**
 * @author DevByEagle
 * @brief Syncio is an open source C/C++ library designed for providing many different functions.
 * @file syncio.h
 * @version 1.0
 */

#ifndef SYNCIO_H
#define SYNCIO_H

#include "types.h"

#ifdef __cplusplus
namespace Syncio {
    /** @brief Outputs a message to the console and appends a newline for better readability. */
    void println(string format, ...);
    
    /** @brief Triggers an error, throwing an exception or terminating the program with a specified message. */
    void raise(string format, ...);
}
#else
/** @brief Outputs a message to the console and appends a newline for better readability. */
void println(const char* format, ...);

/** @brief Triggers an error, throwing an exception or terminating the program with a specified message. */
void raise(const char* format, ...);
#endif

#endif //SYNCIO_H