#ifndef STRINGC_H
#define STRINGC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define String_Print "%s\n"

#ifdef __cplusplus
namespace Syncio {
    /** @brief StringC is a fast, lightweight C/C++ library for efficient string manipulation, offering core functions like concatenation, formatting, and searching, designed for cross-platform use. */
    class StringC {
    public:
	    StringC() : data(nullptr), length(0), isEmpty(nullptr) {}
	    StringC(const char* initial);

	    /** @brief `join` concatenates an array of strings into a single string, separated by a specified delimiter. Ideal for combining multiple text elements efficiently. */
	    void join(const char* additional);
	    /** @brief cmpstr compares two strings lexicographically. Returns 0 if they are equal, a negative value if the first string is less than the second, or a positive value if it is greater. */
	    int cmpstr(const StringC* str) const;
	    bool empty() const;
	    /** @brief `ptrstr`: Prints the string pointed to by a given pointer. Efficiently handles null-terminated strings, ensuring proper output and formatting. */
    	bool ptrstr();
	    /** @brief `size`: Returns the length of the string, excluding the null terminator. */
	    size_t size() const;
	    /** @brief `strfree`: Frees the memory allocated for a string created with StringLib, ensuring proper resource management and preventing memory leaks. */
	    void strfree();
    private:
	    char* data;
	    size_t length;
	    bool isEmpty;
    };
}
#else
#include <stdbool.h>
/** @brief StringC is a fast, lightweight C/C++ library for efficient string manipulation, offering core functions like concatenation, formatting, and searching, designed for cross-platform use. */
typedef struct {
	char* data;
	size_t length;
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