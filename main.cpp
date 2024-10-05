#include "Syncio/syncio.h"
#include "Syncio/synclib.h"

int main() {
  Syncio::Pathio pathio("test.txt");

  if (pathio.load()) {
    std::cout << "File Contents:\n" << pathio.read();
  }
  return 0;
}