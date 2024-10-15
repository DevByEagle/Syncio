/**
 * @author DevByEagle
 * @brief Syncio is an open source C library designed for providing many different functions.
 * @file syncio.h
 * @version 1.0
 */

#ifndef SYNCIO_H
#define SYNCIO_H

#include "types.h"

/** @brief Delays execution for a specified duration, allowing for pauses in program flow. */
void delay(unsigned int ms);

/** @brief Outputs a message to the console and appends a newline for better readability. */
void println(string format, ...);

/** @brief Triggers an error, throwing an exception or terminating the program with a specified message. */
void raise(string format, ...);

#endif // SYNCIO_H