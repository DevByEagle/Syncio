#ifndef SYNCLIB_H
#define SYNCLIB_H

#if defined(_WIN32) || defined(_WIN64)
#include "libs/stringc.h"
#include "../types.h"
#elif __linux__
#include <Syncio/stringc.h>
#include <Syncio/types.h>
#endif

using Syncio::Size_t;

namespace Syncio {
  template <typename T>
  T* xalloc(Size_t cound);
}

#endif // SYNCLIB_H
