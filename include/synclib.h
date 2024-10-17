#ifndef SYNCLIB_H
#define SYNCLIB_H

#if defined(_WIN32) || defined(_WIN64)
#include "types.h"
#include "libs/stringc.h"
#elif __linux__
#include "types.h"
#include "libs/stringc.h"
#endif

namespace Syncio {
  template <typename T>
  T* xalloc(Size_t count);
}

#endif // SYNCLIB_H
