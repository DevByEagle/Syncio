#include "Syncio/syncio.h"
#include "Syncio/utills.h"

using Syncio::delay;

int main() {
  int val = Syncio::random(0, 1000);
  printf("%d\n", val);
  return 0;
}
