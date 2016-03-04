#include <iostream>
// Вместо: void myFunctionMod3();
// Подключаю модуль
#include "module3.h"

using namespace std;

void myFunction() {
  cout << "myFunction()" << endl;
  myFunctionMod3();
}

// Перегрузка функции
void myFunction(int i) {
  cout << "myFunction(int i)" << endl;
  myFunctionMod3();
}

void myFunction(char c) {
  cout << "myFunction(char c)" << endl;
  myFunctionMod3();
}

void myFunction(string s) {
  cout << "myFunction(string c)" << endl;
  myFunctionMod3();
}
