#include <Syncio/syncio.h>
#include <Syncio/utills.h>

using namespace Syncio;

int main(void) {
    ArrayLite array(2);

    array.Append(1);
    array.Append(2);
    array.Append(3);

    for (size_t i = 0; i < array.Size(); i++) {
        printf("%d\n", array.Get(i));
    }

    return 0;
}
