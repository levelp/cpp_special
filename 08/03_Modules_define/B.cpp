#include <iostream>
#include "C.h"
#include <math.h>

using namespace std;

void B_func() {
  cout << "B_func()" << endl;
  C_func();
}

double dist(Point p1, Point p2){
    return sqrt(pow(p1.x - p2.x, 2) +
                pow(p1.y - p2.y, 2));
}
