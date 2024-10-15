#ifndef SYNCLIB_H
#define SYNCLIB_H

#include "syncio.h"

void* xalloc(Size_t size);
void* xrealloc(void* ptr, Size_t new_size);
void xfree(void* ptr);

#endif // SYNCLIB_H