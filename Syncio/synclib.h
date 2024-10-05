#ifndef SYNCLIB_H
#define SYNCLIB_H

#ifdef __cplusplus
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
namespace Syncio {
    class ArrayLite {
    public:
        ArrayLite(size_t initial_capacity) {
            data = (int*)std::malloc(initial_capacity * sizeof(int));
            size = 0;
            capacity = initial_capacity;
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
                data[index] = value;
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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} ArrayLite;

ArrayLite* CreateArrayLite(size_t initial_capacity) {
    ArrayLite* array = (ArrayLite*)malloc(sizeof(ArrayLite));
    array->data = (int*)malloc(initial_capacity * sizeof(int));
    array->size = 0;
    array->capacity = initial_capacity;
    return array;
}

void DestroyArrayLite(ArrayLite* array) {
    free(array->data);
    free(array);
}

void Append(ArrayLite* array, int value) {
    if (array->size >= array->capacity) {
        array->capacity *= 2;
        array->data = (int*)realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size++] = value;
}

int Get(const ArrayLite* array, size_t index) {
    if (index < array->size) {
        return array->data[index];
    }
    return -1; // Or any other error code
}

void Set(ArrayLite* array, size_t index, int value) {
    if (index < array->size) {
        array->data[index] = value;
    }
}

size_t Size(const ArrayLite* array) {
    return array->size;
}

void Clear(ArrayLite* array) {
    array->size = 0;
}

typedef struct {
    char* filePath;     // To store the path of the file
    char* fileContents; // To store the contents of the file
} Pathio;

Pathio* CreatePathio(const char* path) {
    Pathio* pathio = (Pathio*)malloc(sizeof(Pathio));
    pathio->filePath = strdup(path);
    pathio->fileContents = NULL;
    return pathio;
}

void DestroyPathio(Pathio* pathio) {
    free(pathio->filePath);
    free(pathio->fileContents);
    free(pathio);
}

int load(Pathio* pathio) {
    FILE* file = fopen(pathio->filePath, "r"); // Open the file
    if (!file) { // Check if the file opened successfully
        fprintf(stderr, "Error: Could not open file %s\n", pathio->filePath);
        return 0; // false
    }

    // Read the contents of the file
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    pathio->fileContents = (char*)malloc(length + 1);
    fread(pathio->fileContents, 1, length, file);
    pathio->fileContents[length] = '\0'; // Null-terminate the string
    
    fclose(file); // Close the file
    return 1; // true
}

const char* read(const Pathio* pathio) {
    return pathio->fileContents; // Return the contents
}
#endif

#endif // SYNCLIB_H