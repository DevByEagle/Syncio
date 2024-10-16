#ifndef STRINGC_H
#define STRINGC_H

#include <iostream>
#include <cstring>
#include <utility>

namespace Syncio
{
    template <typename T>
    class StringC
    {
    public:
        // Constructors
        StringC() : data(nullptr), length(0) {}

        StringC(const T *initial)
        {
            length = std::strlen(initial);
            data = new T[length + 1];
            std::copy(initial, initial + length, data);
            data[length] = '\0';
        }

        StringC(const StringC &other)
        {
            length = other.length;
            data = new T[length + 1];
            std::copy(other.data, other.data + length, data);
            data[length] = '\0';
        }

        StringC(StringC &&other) noexcept : data(other.data), length(other.length)
        {
            other.data = nullptr;
            other.length = 0;
        }

        // Destructor
        ~StringC()
        {
            delete[] data;
        }

        // Assignment operators
        StringC &operator=(const StringC &other)
        {
            if (this != &other)
            {
                delete[] data;
                length = other.length;
                data = new T[length + 1];
                std::copy(other.data, other.data + length, data);
                data[length] = '\0';
            }
            return *this;
        }

        StringC &operator=(StringC &&other) noexcept
        {
            if (this != &other)
            {
                delete[] data;
                data = other.data;
                length = other.length;
                other.data = nullptr;
                other.length = 0;
            }
            return *this;
        }

        // Concatenation
        StringC operator+(const StringC &other) const
        {
            StringC result;
            result.length = length + other.length;
            result.data = new T[result.length + 1];
            std::copy(data, data + length, result.data);
            std::copy(other.data, other.data + other.length, result.data + length);
            result.data[result.length] = '\0';
            return result;
        }

        // Comparison
        bool operator==(const StringC &other) const
        {
            if (length != other.length)
                return false;
            return std::equal(data, data + length, other.data);
        }

        // Length
        size_t size() const
        {
            return length;
        }

        T* c_str() const {
            return data;
        }

    private:
        T *data;
        size_t length;
    };
}

#endif // STRINGC_H
