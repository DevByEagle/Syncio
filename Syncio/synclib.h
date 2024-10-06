#ifndef SYNCLIB_H
#define SYNCLIB_H

#ifdef __cplusplus
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
namespace Syncio {
    template<typename T>
    class ArrayLite {
    public:
        ArrayLite(size_t initial_capacity) {
            data = (T*)std::malloc(initial_capacity * sizeof(int));
            size = 0;
            capacity = initial_capacity;
        }

        ~ArrayLite() {
            delete[] data;
        }

        void Append(const T& value) {
            if (size >= capacity) {
                capacity *= 2;
                data = (T*)std::realloc(data, capacity * sizeof(int));
            }
            data[size++] = value;
        }

        virtual T Get(size_t index) {
            if (index < size) {
                return data[index];
            }
            throw std::out_of_range("Index out of range");
        }

        virtual void Set(size_t index, const T& value) {
            if (index < size) {
                data[index] = value;
            }
        }

        size_t Size() const {
            return size;
        }

        void Clear() {
            size = 0;
        }

    private:
        T* data;
        std::size_t size;
        std::size_t capacity;
    };

    /*class MathCore {
    };*/

    class Pathio {
    private:
        std::string filePath;   // To store the path of the file
        std::string fileContents; // To store the contents of the file

    public:
        Pathio(const std::string& path) : filePath(path) {}

        bool load() {
            std::ifstream file(filePath); // Open the file
            if (!file.is_open()) {         // Check if the file opened successfully
                std::cerr << "Error: Could not open file " << filePath << std::endl;
                return false;
            }
        
            // Read the contents of the file
            std::string line;
            fileContents.clear(); // Clear previous contents
            while (std::getline(file, line)) {
                fileContents += line + "\n"; // Append line to contents
            }
        
            file.close(); // Close the file
            return true;  // Return true if successful
        }

        std::string read() const {
            return fileContents; // Return the contents
        }
    };
}
#else

#endif

#endif // SYNCLIB_H
