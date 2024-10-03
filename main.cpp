#include "Syncio/syncio.h"
#include "Syncio/utills.h"

using Syncio::MathCore;
using Syncio::delay;

int main() {
  printf("Rounded: %d\n", MathCore::round(4.6f));
  return 0;
}
