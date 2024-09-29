#include "Syncio/syncio.h"

int main() {
    size_t size;
    char* context = fload("log.log", &size);

    if (context) {
        printf("File contents (%zu bytes):\n%s\n", size, context);
        free(context);
    }

    return 0;
}
