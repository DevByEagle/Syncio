#pragma once

typedef unsigned char Uint8_t;
typedef unsigned short Uint16_t;
typedef unsigned long Uint32_t;
typedef unsigned long long Uint64_t;

#ifdef __cplusplus
#include "synclib.h"
using Syncio::ArrayLite;
namespace Syncio {
    typedef void (*SyncEvent)(void);
}
#endif
