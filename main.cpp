#include "Syncio/syncio.h"
#include "Syncio/synclib.h"

struct MyType {
  int id;
  std::string name;
};

int main() {
  Syncio::ArrayLite<MyType> myArray(10);
  MyType obj{1, "example"};
  myArray.Append(obj);
  return 0;
}