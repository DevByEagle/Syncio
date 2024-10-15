#include "../include/synclib.h"

int main() {
    // Example usage of xalloc and xrealloc
    int* array = (int*)xalloc(10 * sizeof(int));  // Allocate memory for 10 integers
    
    // Initialize the array
    for (Size_t i = 0; i < 10; i++) {
        array[i] = i;
        println("array[%u] = %d\n", i, array[i]);
    }
    
    xfree(array);  // Free the allocated memory
    return 0;
}