#ifndef SYNCLIB_H
#define SYNCLIB_H

#ifdef __cplusplus
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <memory>
#include <functional>
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

   template<typename>
   class SyncEvent;

    template <typename ReturnType, typename... Args>
    class SyncEvent<ReturnType(Args...)> {
    public:
        template<typename Callable>
        SyncEvent(Callable&& callable) : impl(std::make_unique<CallableModel<Callable>>(std::forward<Callable>(callable))) {}
    
        SyncEvent() : impl(nullptr) {}

        SyncEvent(SyncEvent&& other) noexcept = default;

        SyncEvent& operator=(SyncEvent&& other) noexcept = default;
        SyncEvent(const SyncEvent&) = default;
        SyncEvent& operator=(const SyncEvent&) = delete;

        ReturnType operator()(Args... args) const {
            if (!impl) throw std::bad_function_call();
            return impl->invoke(std::forward<Args>(args)...);
        }

        explicit operator bool() const noexcept {
            return impl != nullptr;
        }

    private:
        struct CallableBase {
            virtual ~CallableBase() = default;
            virtual ReturnType invoke(Args... args) const = 0;
        };

        template <typename Callable>
        struct CallableModel : CallableBase {
            Callable callable;
            CallableModel(Callable&& c) : callable(std::move(c)) {}
            ReturnType invoke(Args... args) const override {
                return callable(std::forward<Args>(args)...);
            }
        };

        std::unique_ptr<CallableBase> impl;
    };
}
#else

#endif

#endif // SYNCLIB_H
