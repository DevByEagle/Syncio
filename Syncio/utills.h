#ifndef UTILLS_H
#define UTILLS_H

#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
namespace Syncio {
    class ArrayLite {
    public:
        ArrayLite(size_t initial_capacity) {
            data = (int*)malloc(initial_capacity * sizeof(int));
            size = 0;
            capacity = initial_capacity;
        }

        ~ArrayLite() {
            delete[] data;
        }

        virtual void Append(int value) {
            if (size >= capacity) {
                capacity *= 2;
                data = (int*)realloc(data, capacity * sizeof(int));
            }
            data[size++] = value;
        }

        virtual int Get(size_t index) {
            if (index < size) {
                return data[index];
            }
            return -1; // or handle error
        }

        void Set(size_t index, int value) {
            if (index < size) {
                data[index] = value;
            }
        }

        size_t Size() {
            return size;
        }
    private:
        int* data;
        size_t size;
        size_t capacity;
    };

    int random(int min, int max) {
        return (rand() % (max - min + 1)) + min;
    }
}
#else
int random(int min, int max) {
    return (rand() % (max - min + a)) + min;
}
#endif

#endif // UTILLS_H
