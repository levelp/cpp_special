#include <iostream>
#include <conio.h>
#include <malloc.h>
#include <mem.h>

#define SHOW(x) cout << #x << " = " << x << endl;

using namespace std;

// Виды памяти (используемые данным процессом):
// 1. Статическая память
// 2. Динамическая память
// 3. Стек

int i = 0; // Глобальная переменная - статическая память

int m(int a, int b) {
}

double m(double a, double b) {
}

int openWindow() {
  static int totalWindows = 0;
  totalWindows++;
  cout << "Open window #" << totalWindows << endl;
}

const int incSize = 10000;

int f() {
  static int calls = 0;
  calls++;
  cout << "calls = " << calls << endl;
  int inStack[incSize];
  f();
}

// 1. Статическая память
//  - Выделяется при старте и очищается при завершении программы
//   Глобальные переменные
//   Переменные, у которых стоит слово static
const int SIZE = 100 * 1024 * 1024;
int bigArray[SIZE]; // Статическая память

void f2() {
  static int calls = 0; // Количество вызовов функции f
  calls++;
  cout << "f2() #" << calls << endl;
}

// Функция, которая возвращает
// среднее значение всех переданных в неё значений
double average(double x) {
  static double sum = 0.0;
  static int N = 0;
  N++; // Количество значений
  sum += x; // Сумма всех значений
  return sum / N;
}

void rec(int N) {
  int a, b, c, d, e, f;
  int myArray[10000];
  for(int i = 0; i < 10000; i++)
    myArray[i] = i;
  SHOW(N);
  rec(N + 1);
}

int main() {
  cout << 51 * 10000 * sizeof(int) << endl;

  rec(0); // переполнение стека

  openWindow();
  openWindow();
  openWindow();

  // Функция возвращает каждый раз среднее для всех
  SHOW(average(2.0));
  SHOW(average(3.0));
  SHOW(average(1.0));
  SHOW(average(4.0));
  SHOW(average(5.0));
  SHOW(average(1.0));

  for(int i = 0; i < SIZE; ++i)
    bigArray[i] = i;

  cout << "sizeof(bigArray) = " << sizeof(bigArray) << endl;

  // 3. Стек (Stack)
  //  - выделяется в момент вызова функции или входа в блок
  //  (если несколько блоков внутри функции)
  //  - переменная удаляется когда мы достигаем границы области видимости
  int x;
  int anyName[100]; // Объявили массив в стеке
  // FILO
  for(int i = 0; i < 10; i++) { // Переменная i заводится в стеке в начале цикла

  } // i верняя переменная в стеке (на верщине стека)
  // удаляется


  // Тип_данных* имя_переменной; // Объявление указателя
  int* intPtr;
  // Нетипизированный указатель
  void* ptr; // Pointer

  cout << sizeof(intPtr) << endl;

  // Заводим в динамической памяти массив из 1024*1024 элементов
  // с типом int
  for(int i = 0; i < 3; i++) {
    intPtr = new int[1024 * 1024]; // Утечка памяти
    //intPtr = //malloc(1000000); // malloc - С
    for(int j = 0; j < 1024 * 1024; j++)
      intPtr[j] = j;
    cout << "i = " << i << " " << (i + 1) * 1024LL * 1024 * 4 <<  endl;
    //getch();
  }

  // Удалили
  delete[] intPtr;  // delete varName;
  // delete[] arrayName;

  char* str;
  str = new char[200000000]; // new - С++

  delete str;

  intPtr = (new int[100]) + 2;
  // *(intPtr + 19*sizeof(int));
  intPtr = new int[100];

  // Массив байт в динамической памяти
  void* buf = malloc(1000000);
  int ints[100];
  memcpy(buf + 10000, ints, sizeof(int) * 100);
  memcpy(buf + 10000, ints, sizeof(ints));
  free(buf); // парная к malloc

  return 0;
}
