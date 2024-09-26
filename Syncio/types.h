#pragma once

#ifdef __cplusplus
namespace Syncio {
    typedef unsigned char Uint8_t;
    typedef unsigned short Uint16_t;
    typedef unsigned long Uint32_t;
    typedef unsigned long long Uint64_t; 
}
#else
typedef unsigned char Uint8_t;
typedef unsigned short Uint16_t;
typedef unsigned long Uint32_t;
typedef unsigned long long Uint64_t;
typedef Uint8_t UBool;
#define true (UBool)1
#define false (UBool)0
#endif