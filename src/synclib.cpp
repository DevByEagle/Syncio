#include "../include/syncio.h"
#include "../include/synclib.h"

template <typename T>
T* xalloc(Size_t count) {
  T* ptr = static_cast<T*>(std::malloc(count * sizeof(T)));
  if (ptr == nullptr) {
    raise("Memory allocation failed\n");
  }
  return ptr;
}

