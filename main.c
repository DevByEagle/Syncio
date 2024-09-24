#include "Syncio/syncio.h"

int main() {
    FILE* file = fload("log.log", "wb");
    fprintf(file, "Info");
    return 0;
}