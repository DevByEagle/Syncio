#ifndef SYNCLIB_H
#define SYNCLIB_H

#ifdef __cplusplus
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <vector>
#include <new>
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

    template<typename T>
    class xalloc {
    private:
        class Block {
        public:
            size_t size;     // Size of the block
            Block* next;     // Pointer to the next block
            bool free;       // Free status (true: free, false: used)

            Block(size_t s) : size(s), next(nullptr), free(true) {}
        };

        Block* freeList;    // Pointer to the free list

    public:
        xalloc() {
            freeList = static_cast<Block*>(malloc(sizeof(Block) + 64));
            if (!freeList) {
                std::cerr << "Memory allocation failed!" << std::endl;
                exit(1);
            }
            freeList->size = 64;
            freeList->next = nullptr;
            freeList->free = true;
        }

        ~xalloc() {
            cleanAllocator();
        }

        T* allocate(size_t count = 1) {
            size_t size = sizeof(T) * count;
            // Align the requested size to the nearest multiple of 8
            size = (size + 7) & ~7;
            Block* current = freeList;

            while (current) {
                // Check if the block is free and large enough
                if (current->free && current->size >= size) {
                    current->free = false; // Mark as used
                    return static_cast<T*>(reinterpret_cast<T*>(current) + sizeof(Block));
                }
                current = current->next;
            }

            // If no free block found, allocate a new block
            Block* newBlock = static_cast<Block*>(malloc(size + sizeof(Block)));
            if (!newBlock) {
                std::cerr << "Memory allocation failed!" << std::endl;
                return nullptr;
            }

            newBlock->size = size;
            newBlock->free = false;
            newBlock->next = freeList; // Add to the free list
            freeList = newBlock;

            return static_cast<T*>(reinterpret_cast<T*>(newBlock) + sizeof(Block));
        }

        void deallocate(T* ptr) {
            if (!ptr) return;

            Block* block = reinterpret_cast<Block*>(reinterpret_cast<T*>(ptr) - sizeof(Block));
            block->free = true;
        }

        void cleanAllocator() {
            Block* current = freeList;
            while (current) {
                Block* next = current->next;
                free(current);
                current = next;
            }
        }
    };
}
#else

#endif

#endif // SYNCLIB_H
