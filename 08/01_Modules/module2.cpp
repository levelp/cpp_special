#include <iostream>
// Вместо: void myFunctionMod3();
// Подключаю модуль
#include "module3.h"

using namespace std;

void myFunction() {
  cout << "myFunction()" << endl;
  myFunctionMod3();
}
