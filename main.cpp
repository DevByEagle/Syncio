#include "Syncio/syncio.cpp"
#include "Syncio/stringc.cpp"

int main() {
    Syncio::StringC str("Hello World");
    if (str.empty() == true) {
        exit(1);
    } else {
        str.ptrstr();
    }
    return 0;
}