#include "Syncio/syncio.h"
#include "Syncio/synclib.h"

void myfunction(void) {
  std::cout << "Hello World" << std::endl;
}

int main() {
  Syncio::SyncEvent func = myfunction;
  func();
  return 0;
}
