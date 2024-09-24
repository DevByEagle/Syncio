#include "Syncio/syncio.h"
#include "Syncio/stringc.c"

int main() {
    StringC str = strinit("Hello, ");
    join(&str, "World!");
    ptrstr(&str);
    return 0;
}