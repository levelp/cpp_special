#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool inArray(int value, int* arr, int N) {
  for (int i = 0; i < N; ++i) {
    if (arr[i] == value) {
      cout << "arr[i] = " << arr[i] << ", value = " << value << " on i = " << i << endl;
      return true;
    }
  }
  return false;
}

int regNewValue(int value, int** carr, int N) {
  for (int i = 0; i < N; ++i) {
    if (carr[0][i] == value) {
      carr[1][i]++;
      return carr[1][i];
    }
  }
  // nil - Delphi, NULL - C/C++, null - Java
  for (int i = 0; i < N; ++i) {
    //как правильно задавать пустой элемент числового массива?
    if (carr[0][i] == 0) {
      carr[0][i] = value;
      carr[1][i] = 1;
      return 1;
    }
  }
  return 0;
}

int main() {
  setlocale(LC_ALL, "Russian");

  int N;
  cout << "Введите длину массива [N]: ";
  cin >> N;

  // В стеке два указателя: arr, carr
  int* arr = new int[N]; // С помощью new сам массив создаём в динамической памяти
  int** carr = new int* [2];
  for (int i = 0; i < 2; i++) { // Инициализируем каждую строчку массива
    carr[i] = new int[N];
    memset(carr[i], 0, sizeof(int) * N);
  }

  for (int i = 0; i < N; ++i) {
    cout << "Задайте элемент [" << i << "]: ";
    int value;
    cin >> value;
    regNewValue(value, carr, N);
    arr[i] = value;
  }

  cout << "Исходный массив: ";
  for (int i = 0; i < N; ++i)
    cout << arr[i] << " ";
  cout << endl;

  //просчёт длины нового массива
  cout << "Количество элементов: ";
  int newLen = N;
  for (int i = 0; i < N && carr[1][i] != INT_MIN; ++i) {
    int c = carr[1][i];
    cout << carr[0][i] << "(" << c << ") ";
    newLen -= (c > 1) ? c : 0;
  }
  cout << endl;

  cout << "newLen = " << newLen << endl;

  //заполнение нового массива
  int* narr = new int[newLen];
  for (int i = 0, j = 0; i < N; ++i) {
    if (carr[1][i] == 1)
      narr[j++] = carr[0][i];
  }

  //вывод нового массива
  cout << "Новый массив: ";
  for (int i = 0; i < newLen; ++i)
    cout << narr[i] << " ";
  cout << endl;

  delete[] narr;
  delete[] arr;
  for (int i = 0; i < 2; i++)
    delete[] carr[i];
  delete[] carr;  // нужен
  return 0;
}
