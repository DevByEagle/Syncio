#ifndef STRINGC_H
#define STRINGC_H

#include <iostream>
#include <cstring>
#include <utility>

namespace Syncio {
    template<typename CharT>
    class StringC {
    public:
       StringC() : data(nullptr), length(0), isEmpty(true) {}

       StringC(const CharT* initial) {
        length = std::strlen(initial);
        data = new CharT[length + 1];
        std::copy(initial, initial + length, data);
        data[length] = '\0';
       }


    private:
       CharT* data;
       std::size_t length;
       bool isEmpty;
    };
}

#endif // STRINGC_H