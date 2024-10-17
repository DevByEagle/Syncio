#ifndef SYNCLIB_H
#define SYNCLIB_H

#include "libs/stringc.h"

namespace Syncio {
  namespace Foundation {
    template <typename CharT>
    class base_string : public StringC<CharT>;
  }
}

#endif // SYNCLIB_H
