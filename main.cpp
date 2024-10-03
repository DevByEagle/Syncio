#include "Syncio/syncio.h"
#include "Syncio/utills.h"
bool isEven(int value) {
  return value % 2 == 0;
}

int main() {
  Syncio::ArrayLite array(10);
  array.Append(1);
  array.Append(2);
  array.Append(3);
  array.Append(4);

  Syncio::ArrayLite* filteredArray = array.Filter(isEven);

  for (size_t i = 0; i < filteredArray->Size(); i++) {
    printf("%d\n", filteredArray->Get(i));
  }

  delete filteredArray;

  return 0;
}