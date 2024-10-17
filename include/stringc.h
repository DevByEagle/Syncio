#ifndef STRINGC_H
#define STRINGC_H

#include "syncio.h"

#ifdef __cplusplus
#include <cstring>
#include <utility>
#include <algorithm>
namespace Syncio {
    /** @brief StringC is a fast, lightweight C/C++ library for efficient string manipulation, offering core functions like concatenation, formatting, and searching, designed for cross-platform use. */
    template <typename T>
    class StringC {
    public:
        StringC() : data(nullptr), length(0) {}

        StringC(const T* initial) {
            length = std::strlen(initial);
            data = new T[length + 1];
            std::copy(initial, initial + length, data);
            data[length] = '\0';
        }

        StringC(const StringC& other) {
            length = other.length;
            data = new T[length + 1];
            std::copy(other.data, other.data + length, data);
            data[length] = '\0';
        }

        StringC(StringC&& other) noexcept : data(other.data), length(other.length) {
            other.data = nullptr;
            other.length = 0;
        }

        ~StringC() {
            delete[] data;
        }

        // Assignment operators
        StringC& operator=(const StringC& other) {
            if (this != &other) {
                delete[] data;
                length = other.length;
                data = new T[length + 1];
                std::copy(other.data, other.data + length, data);
                data[length] = '\0';
            }
            return this;
        }

        StringC& operator=(StringC&& other) noexcept {
            if (this != &other) {
                delete[] data;
                data = other.data;
                length = other.length;
                other.data = nullptr;
                other.length = 0;
            }
            return this;
        }

        bool empty() const {
            return length == 0;
        }

        std::size_t size() const {
            return length;
        }

        static StringC join(const StringC* strings, std::size_t count, const StringC& separator = StringC("")) {
            // Calculate total length needed
            std::size_t total_length = 0;
            for (std::size_t i = 0; i < count; i++) {
                total_length += strings[i].length;
                if (i < count - 1) {
                    total_length += separator.length;
                }
            } 

            // Allocate memory for the final result
            StringC result;
            result.length = total_length;
            result.data = new T[total_length + 1];

            std::size_t pos = 0;
            for (std::size_t i = 0; i < count; i++) {
                std::copy(strings[i].data, strings[i].data + strings[i].length, result.data + pos);
                pos += strings[i].length;

                if (i < count - 1) {
                    std::copy(separator.data, separator.data + separator.length, result.data + pos);
                    pos += separator.length;
                }
            }

            result.data[total_length] = '\0';
            return result;
        }

        static StringC join(const StringC& str1, const StringC& str2) {
            const StringC strings[] = { str1, str2 };
            return join(strings, 2);
        }

        const T* c_str() const {
            return data;
        }

    private:
        T* data;
        std::size_t length;
    };
}
#else
#include <stdbool.h>
/** @brief StringC is a fast, lightweight C/C++ library for efficient string manipulation, offering core functions like concatenation, formatting, and searching, designed for cross-platform use. */
typedef struct {
	char* data;
	Size_t length;
} StringC;

/** @brief strinit initializes and returns a new string, allocating memory and setting the content to a specified value. */
StringC strinit(const char* initial);
/** @brief `join` concatenates an array of strings into a single string, separated by a specified delimiter. Ideal for combining multiple text elements efficiently. */
void join(StringC* str, const char* additional);
/** @brief cmpstr compares two strings lexicographically. Returns 0 if they are equal, a negative value if the first string is less than the second, or a positive value if it is greater. */
int cmpstr(const StringC* str1, const StringC* str2);
/** @brief `ptrstr`: Prints the string pointed to by a given pointer. Efficiently handles null-terminated strings, ensuring proper output and formatting. */
bool ptrstr(const StringC* str);
/** @brief `size`: Returns the length of the string, excluding the null terminator. */
size_t size(StringC* str);
/** @brief `strfree`: Frees the memory allocated for a string created with StringLib, ensuring proper resource management and preventing memory leaks. */
void strfree(StringC* str);
#endif

#endif // STRINGC_H