#include "Syncio/syncio.h"
#include "Syncio/utills.h"

using Syncio::delay;

int main() {
  bool isRunning = true;

  while (isRunning) {
    int val = Syncio::random(0, 10000);
    printf("%d\n", val);
    #ifdef __liunx__
    delay(1000);
    #else
    delay(200);
    #endif
  }
}