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

        void Append(int value) {
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
            return -1;
        }

        virtual void Set(size_t index, int value) {
            if (index < size) {
                data[index] = value;
            }
        }

        size_t Size() {
            return size;
        }

        ArrayLite* Filter(bool (*predicate)(int)) {
            ArrayLite* result = new ArrayLite(capacity); // Create a new ArrayLite for the filtered result
            for (size_t i = 0; i < size; i++) {
                if (predicate(data[i])) {
                    result->Append(data[i]); // Append to the new ArrayLite if it satisfies the predicate
                }
            }
            return result; // Return the new filtered ArrayLite
        }
    private:
        int* data;
        size_t size;
        size_t capacity;
    };
    
    class MathCore {
        public:
        static int round(float num) {
            if (num >= 0) {
                return (int)(num + 0.5f);
            } else {
                return (int)(num - 0.5f);
            }
        }

        static int floor(float num) {
            int intPart = (int)num;
            return (num < intPart) ? (intPart - 1) : intPart;
        }

        static float square(float num) {
            return num * num;
        }
    };
}
#else
#endif

#endif // UTILLS_H