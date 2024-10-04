#ifndef SYNCLIB_H
#define SYNCLIB_H

#ifdef __cplusplus
#include <iostream>
#include <cstdlib>
#include <stddef.h>
namespace Syncio {
    class ArrayLite {
    public:
        ArrayLite(size_t initial_capacity) {
            data = (int*)std::malloc(initial_capacity * sizeof(int));
            size = 0;
            capacity = initial_capacity
        }

        ~ArrayLite() {
            delete[] data;
        }

        void Append(int value) {
            if (size >= capacity) {
                capacity *= 2;
                data = (int*)std::realloc(data, capacity * sizeof(int));
            }
            data[size++] = value;
        }

        virtual int Get(size_t index) {
            if (index < size) {
                return data[index];
            }
            return -1;
        }

        virtual void Set(size_t index, int value) {
            if (index < size) {
                data[index] = value
            }
        }

        size_t Size() {
            return size;
        }

        void Clear() {
            size = 0;
        }

    private:
        int* data;
        size_t size;
        size_t capacity;
    };

    /*class MathCore {
    };*/
    /*class Pathio {
    } */
}
#else
#include <stdio.h>
#include <stdlib.h>
#endif

#endif // SYNCLIB_H