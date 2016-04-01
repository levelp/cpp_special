#include <iostream>
#include "B.h"
#include "C.h"

using namespace std;

void A_func() {
  cout << "A_func()" << endl;
  C_func();
  Point p1 = {1, 2}, p2 = {3, 4};
  cout << dist(p1,p2) << endl;
}
