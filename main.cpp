#include "Syncio/syncio.h"
#include "Syncio/synclib.h"

int main() {
    Syncio::SyncEvent<int(int, int)> add = [](int a, int b) { return a + b; };

    if (add) {  // Check if the function is valid
        std::cout << "Result: " << add(3, 4) << std::endl;  // Output: Result: 7
    }

    return 0;
}
