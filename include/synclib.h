#ifndef SYNCLIB_H
#define SYNCLIB_H

#include "types.h"

namespace Syncio {
  template <typename T>
  T* xalloc(Size_t count);

  template <typename T>
  void xfree(T* ptr);
}

#endif // SYNCLIB_H
