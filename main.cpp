#include "Syncio/syncio.h"
#include "Syncio/utills.h"

using namespace Syncio;

int main() {
  bool isRunning = true;

  while (isRunning == true) {
    int val = Syncio::random(0, 1000000);
    printf("%d\n", val);
    Syncio::delay(2000);
  }
}
