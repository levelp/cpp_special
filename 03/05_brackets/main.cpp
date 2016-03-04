#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

// Строка со скобками
char s[100] = {0};

int N = 4; // Количество пар скобок

// open - количество поставленных открывающих скобок
// close - количество поставленных закрывающих скобокы
void f(int open, int close) {
  // Все скобки уже поставлены
  if(open == N && close == N) {
    cout << s << endl;
    return;
  }
  int p = open + close; // Текущая позиция
  // Открывающую скобку
  if(open < N) {
    s[p] = '(';
    f(open + 1, close);
  }
  // Закрывающую скобку
  if(close < open) {
    s[p] = ')';
    f(open, close + 1);
  }
}

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

// "abc" < "adb"

void show(char c) {
  int code = (unsigned char)c;
  cout << c << " " << setw(5) << code;
  printf(" %02X ", code);
  showBits3(c);
}

int main() {
  // setlocale(LC_ALL, "Russian");

  f(0, 0);

  show('(');
  show(')');
  char* str = "Я";
  show(str[0]);
  show(str[1]);
  show('x');
  show('f');
  return 0;
}
