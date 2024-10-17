#pragma once

#if defined(_WIN32) || defined(_WIN64)
#include "libs/stringc.h"
#elif __linux__
#include <Syncio/stringc.h>
#endif
