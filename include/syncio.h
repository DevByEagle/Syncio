/**
 * @author DevByEagle
 * @brief Syncio is an open source C library designed for providing many different functions.
 * @file syncio.h
 * @version 1.0
 */

#ifndef SYNCIO_H
#define SYNCIO_H

#include "types.h"

void delay(unsigned int ms);

/** @brief Prints Text to the Terminal. */
void println(string format, ...);

//int raise(FILE* stream, string format, ...);

#endif // SYNCIO_H