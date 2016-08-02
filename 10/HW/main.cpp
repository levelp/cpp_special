#include <iostream>
#include <stdlib.h>

using namespace std;

#define SHOW(x) cout << #x << " = " << (x) << endl;
#define SIZE(array) (sizeof(array) / sizeof(array[0]))

void showArray(int mas[], int size){
    for(int i = 0; i < size; i++)
        cout << "mas[" << i << "] = " << mas[i] << endl;
}

int main()
{
    int mas[] = {1, 2, 3};
    // В той же области видимости можем определить размер массива констант
    for(int i = 0; i < SIZE(mas); i++)
        cout << "mas[" << i << "] = " << mas[i] << endl;
    // А в функцию его придётся передать...
    showArray(mas, SIZE(mas));

    int n = 9;
    int *p = &n;
    cout << "p = " << *p << endl;
    return 0;
}
