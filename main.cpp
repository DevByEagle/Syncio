#include "Syncio/synclib.h"
#include "Syncio/syncio.h"

int main() {
    // Using xalloc
    Syncio::xalloc<int> allocator;

    // Allocate memory for 5 integers
    int* nums = allocator.allocate(5);
    if (!nums) {
        std::cerr << "Allocation failed!" << std::endl;
        return 1;
    }

    // Initialize and print the allocated integers
    for (size_t i = 0; i < 5; ++i) {
        nums[i] = static_cast<int>(i * 10);
        std::cout << "nums[" << i << "] = " << nums[i] << std::endl;
    }

    // Deallocate the memory
    allocator.deallocate(nums);

    // Using ArrayLite
    Syncio::ArrayLite array(2); // Initial capacity of 2
    array.Append(10);
    array.Append(20);
    array.Append(30); // Should trigger a resize

    std::cout << "ArrayLite contents:" << std::endl;
    for (size_t i = 0; i < array.Size(); ++i) {
        std::cout << "array[" << i << "] = " << array.Get(i) << std::endl;
    }

    // Clear the array
    array.Clear();
    std::cout << "ArrayLite size after clearing: " << array.Size() << std::endl;

    // Using Pathio
    Syncio::Pathio pathio("example.txt"); // Make sure this file exists
    if (pathio.load()) {
        std::cout << "File contents:" << std::endl;
        std::cout << pathio.read() << std::endl;
    } else {
        std::cerr << "Failed to load the file." << std::endl;
    }

    return 0;
}
