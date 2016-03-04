/// Типы данных
/// ===========
#include <iostream>
#include <iomanip> // IO manipulations
#include <string.h> // Для работы со строками
#include <stdio.h> // printf

using namespace std;

// void - функция, которая ничего не возвращает
// unsigned - просто тип int
void showBits(unsigned long long N, unsigned size) {
  for(int byte = size - 1; byte >= 0; --byte) {
    for(int bit = 7; bit >= 0; --bit) {
      // 7,6,5,4,3,2,1,0
      // При bit = 2, выделение бита работает так:
      //   0b1011011101
      //     9876543210    b0*2^0 + b1*2^1 + ...
      //            x
      //   0b1011011101
      //            x-->
      //   0b0010110111
      // & 0b0000000001 - маска
      // bitValue - значение бита bit в байте byte
      // & - побитовое И
      int bitNumber = byte * 8 + bit; // Номер бита в числе
      int bitValue = (N >> bitNumber) & 1;
      cout << bitValue;
    }
    cout << " ";
  }
  cout << endl;
}

int getBit(unsigned long long N, int bit) {
  return (N >> bit) & 1;
}

void showBits2(unsigned long long N, unsigned size) {
  // Номер бита в числе
  // 7,6,5,4,3,2,1,0
  for(int bit = size * 8 - 1; bit >= 0; --bit) {
    cout << getBit(N, bit);
    if(bit % 8 == 0)
      cout << " ";
  }
  cout << endl;
}

// Dijkstra

template <typename T>
int getBit3(T N, int bit) {
  return (N >> bit) & 1;
}

// Использование шаблонов
template <typename T> // Шаблонизирует только ближайшее определение
void showBits3(T N) {
  // Номер бита в числе
  // 7,6,5,4,3,2,1,0
  for(int bit = sizeof(T) * 8 - 1; bit >= 0; --bit) {
    cout << getBit3(N, bit);
    if(bit % 8 == 0)
      cout << " ";
  }
  cout << endl;
}

// N - исходное число
// i - номер бита
// B - новое значение бита
int setBit(int N, int i, int B) {
  //   76543210
  // 0b01000101  - N
  //    x
  //          X
  int R = N;
  // Очистим бит i
  //   76543210
  //    x
  //  (1 << i)
  // 0b01000000
  //  ~(1 << i) - инверсия бит
  // 0b10111111
  R = R & ( ~(1 << i) );
  //    x
  // 0b00000101 - R
  // Устанавливаем значение бита с номером i в числе t в значение B
  int t = (B << i);
  //    x
  // 0b0B000000
  // "Вставляем" бит i в результат R
  R = R | t;
  return R;
}

int main() {
  // Примитивные типы данных
  //   Целые типы данных
  //     По размеру: 1,2,4,8 байт
  //     Со знаком или без:
  //       unsigned - без знака (не могут быть меньше 0)
  //       signed - со знаком
  char c; // 1 байт
  signed char s; // -128..127
  // Первый бит означает знак: 0 - "+", 1 - "-"
  // 00000000 - 0
  // 00000001 - 1
  // ...
  // 01111111 - 127
  // 10000000 - -128
  // 10000001 - -127
  // ...
  // 11111111 - -1
  unsigned char uc; // 0..255

  uc = -1; // 255
  uc = 257; // 256 + 1  =>  +1

  // 2 байта - 16 бит
  short sh; // -32768..32767
  signed short ssh;
  unsigned short ush; // 0..65535   0..2^16-1
  // Переполнения так же, как с char

  // 4 байта - 32 бита
  // Размер равен битности компилятора
  //  16 битный компилятор (Borland C++) - 16 бит
  //  32 битный - 32 бита
  //  64 битный - 64 бита
  int i; // signed int
  unsigned int ui;
  unsigned uu; // просто тип int
  signed int si = (1 << 31) - 1;
  cout << "MAX_INT = " << si << endl;
  cout << "INT " << (- (1 << 31)) << ".." << ((1 << 31) - 1) << endl;

  ui = (1 << 32) - 1;
  cout << "MAX_UNSIGNED_INT = " << ui << endl;
  si = ui;
  cout << "si = " << si << " ui = " << ui << endl;

  long l; // signed / unsigned
  // Для 32-битных компиляторов равен int
  //  16 битный компилятор (Borland C++) - 32 бита
  //  32 битный - 32 бита
  //  64 битный - 64 бита

  // 8 байт - 64 бита
  long long ll = (1LL << 63) - 1;
  signed long long sll = (1LL << 63) - 1; // LL - signed LL
  // Максимальное число представимое в стандартных типахы
  unsigned long long ull = (1ULL << 64) - 1;
  cout << "MAX_ULL = " << ull << endl;
  // Сдвиг:  "<<"

  uc = -1;
  showBits(uc, 1);

  int ii = 512;
  showBits(ii, sizeof(int));
  showBits(ull, sizeof(ull));

  showBits3(ull);

  showBits3(10);
  showBits3(10LL);
  showBits3('A');
  showBits3(sh);

  unsigned char x = 0b00010101;
  showBits3(x);
  x = setBit(x, 6, 1);
  showBits3(x);
  x = setBit(x, 0, 0);
  showBits3(x);

  // Действительные числа
  // 4 байта 32 битный
  float fl = 1.0; // В памяти создаётся константа с типом double, при выполнении приводится
  // к типу float
  float flF = 1.1f; // f - константа с типом float
  // 8 байт 64 битный
  double dbl = 3.14;
  // Минимум 10 байт, но может быть и больше
  //  80 бит, 96 бит, 128 бит
  long double ldbl = 3.12;

  // Логический тип
  bool b = true;
  b = false;
  // Используется тернарный оператор для вывода значения
  cout << "b = " << ((b) ? "true" : "false") << endl;
  cout << "b = " << true << " " << false << endl;
  // Скорее всего неправильное применение - плохая практика!
  long double ldbl2 = true;

  // Строки (массивы и указатели мы пройдём позже)
  char* myStr = "Hello!"; // В памяти хранится константа "Hello!" + символ 0 на конце
  for(int i = 0; i <= strlen(myStr); ++i) {
    cout << i << " " << myStr[i] << " " << setw(5) << (int)myStr[i] << " "  << " ";
    showBits3(myStr[i]);
  }

  char myStr2[] = "Hello!"; // 7 элементов в массиве

  char myStr3[30] = "Hello!"; // 30 элементов в массиве, но инициализируем только первые 7

  for(int i = 0; i < 30; ++i) {
    cout << setw(4) << i << " " << myStr3[i] << " " << setw(5) << (int)myStr3[i];
    printf(" %02X ", (int)myStr3[i]);
    showBits3(myStr3[i]);
  }

  // Заменяем второй символ на '#'
  myStr2[1] = '#';
  cout << myStr2 << endl;

  //
  int len = 30;
  cin >> len;
  char myStr4[len];

  char* myStr4 = new char[len];
  char* ptr, value;
  char* ptr2, *value2;

  return 0;
}
