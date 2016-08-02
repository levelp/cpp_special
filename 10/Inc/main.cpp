#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    ++x;
    x = x++;
    cout << "x = " << x << endl;
    return 0;
}
