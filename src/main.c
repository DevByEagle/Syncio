#include <stdio.h>
#include "../include/syncio.h"

void callback(string arg) {
    printf("%s\n", arg);
}

int main() {
    delay(1);
    callback("Hello World");
    return 0;
}