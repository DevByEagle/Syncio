#pragma once

#include "synclib.h"

#ifdef __cplusplus
namespace Syncio {
    using string = StringC<char>;
    typedef unsigned long Size_t;
}
#else
typedef unsigned long Size_t;
#endif