#include <iostream>
#include "Syncio/utills.h" // Make sure to include the header file

int main() {
    // Create an ArrayLite instance with an initial capacity of 4
    Syncio::ArrayLite myArray(4);

    // Append some values
    myArray.Append(10);
    myArray.Append(20);
    myArray.Append(30);
    myArray.Append(40);
    
    // Print the current size and contents
    std::cout << "Size after appending: " << myArray.Size() << std::endl;
    for (size_t i = 0; i < myArray.Size(); i++) {
        std::cout << "Element at index " << i << ": " << myArray.Get(i) << std::endl;
    }
    
    // Clear the array
    myArray.Clear();
    std::cout << "\nSize after clearing: " << myArray.Size() << std::endl;

    // Append again after clearing
    myArray.Append(50);
    myArray.Append(60);
    
    // Convert to C-style array
    int* cArray = myArray.ToArray();
    std::cout << "\nContents of C-style array:" << std::endl;
    for (size_t i = 0; i < myArray.Size(); i++) {
        std::cout << "Element at index " << i << ": " << cArray[i] << std::endl;
    }

    // Free the C-style array
    free(cArray);

    return 0;
}
