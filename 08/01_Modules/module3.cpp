#include <iostream>
#include "module3.h"
#include "subdir/module4.h"

using namespace std;

void myFunctionMod3() {
  cout << "myFunctionMod3()" << endl;
  myFunctionMod4();
}
