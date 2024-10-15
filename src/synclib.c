#include <stdio.h>
#include <stdlib.h>

#include "../include/synclib.h"

void* xalloc(Size_t size) {
    if (size <= 0) {
        println("Invalid size\n");
        //raise(stderr, "Invalid size\n");
        exit(EXIT_FAILURE);
    }

    void* ptr = malloc(size);
    if (!ptr) {
        println("Invalid size\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void* xrealloc(void* ptr, Size_t new_size) {
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    void* new_ptr = realloc(ptr, new_size);
    if (!new_ptr) {
        println("Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }

    return new_ptr;
}

void xfree(void* ptr) {
    free(ptr);
}