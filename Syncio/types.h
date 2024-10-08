#pragma once

#define BLOCK_SIZE 64 // Size of the memory block

typedef unsigned char Uint8_t;
typedef unsigned short Uint16_t;
typedef unsigned long Uint32_t;
typedef unsigned long long Uint64_t;

#ifdef __cplusplus
namespace Syncio {
    typedef void (*SyncEvent)(void);
}
#else
typedef void (*SyncEvent)(void);
#endif
