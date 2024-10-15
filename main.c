#include "include/syncio.h"

int main() {
    char* prompt = input("Enter something: ");
    if (prompt) {
        println("You entered: %s\n", prompt);
    } else {
        raise("Failed to allocate memory.\n");
    }
    return 0;
}