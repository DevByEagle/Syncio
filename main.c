#include "Syncio/syncio.h"
#include "Syncio/stringc.c"

int main() {
    char* str = tostring(10);
    printf("%s\n", str);
    return 0;
}