#include <cstdlib>

#include "../include/syncio.h"
#include "../include/synclib.h"

template <typename T>
T* Syncio::xalloc(Size_t count) {
  T* ptr = static_cast<T*>(std::malloc(count * sizeof(T)));
  if (!ptr) {
    raise("Failded to allocate memory\n");
    return nullptr;
  }
  return ptr;
}
