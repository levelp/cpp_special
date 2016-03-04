/// Один и тот же модуль подключается 2-мя путями
///   main - подключает модуль A и модуль B
///   Модуль A и модуль B подключают C
#include <iostream>
#include "A.h"
#include "B.h"

using namespace std;

int main() {
  A_func();
  B_func();
  return 0;
}
