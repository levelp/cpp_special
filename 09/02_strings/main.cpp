/// Работа со строчками
/// ===================
/// Документация с базовыми функциями
/// http://ru.cppreference.com/w/cpp/string/basic_string
#include <iostream>
#include <cstring> // Функции для работы со строчками из C
#include <string> // C++
#include <stdexcept>
#include <sstream>

using namespace std;

int main() {
  string s = "Hello world!";
  string s2 = s;
  cout << "H -> " << s2[0] << endl;
  s2[0] = 'A';
  cout << s2 << endl;
  try {
    // Проверка на выход за границы
    cout << s2.at(15) << endl;
  } catch(out_of_range ex) { // Аналог except в Delphi
    cout << "Exception: " << ex.what() << endl;
  }

  // Размер строки в символах
  cout << "s2.size() = " << s2.size() << endl;

  // К строке прибавить 5 пробелов
  s2 += "     ";
  s2 += string(5, ' '); // Создаём новую строчку из 5 пробелов и добавляем
  // к существующей

  // Создаём пустую строчку заданного размера
  int N = 1000;
  string str(N, 0); // Создаём строчку на 1000 символов
  cout << "str.size() = " << str.size() << endl;

  string str2 = "";
  for(int i = 0; i <= 9; i++) {
    str2 += ('0' + i); // При этом i конвертируется в число
    cout << "size = " << str2.size() << "  capacity = " << str2.capacity() << " \"" <<
         str2 << "\"" << endl;
  }
  //
  for(int i = '0'; i <= '0' + 15; i++)
    cout << i << " -> '" << (char)i << "'  ";
  cout << endl;

  // 1000 -> '1000'
  // 1 -> '1'
  cout << "String stream" << endl;
  cout << "=============" << endl;
  stringstream strStream;
  int n = 1000;
  int m = 110;
  strStream << "n = " << n << " ";
  strStream << "m = " << m;

  cout << strStream.str() << endl;


  string str3 = "abcd";
  string str4 = str3.substr(0, 3); // Аналог copy
  cout << "str4 = \"" << str4 << "\"" << endl;

  // Получаем из C++ экземпляра класса string C-строку
  // т.е. указатель на массив символов (char*)
  const char* cTmp = str4.c_str(); // .c_str() - метод
  cout << "cTmp = " << cTmp << endl;
  // сTmp удалять не нужно, потому что это указатель на
  // внутреннее представление

  // Получаем C++ строчку из C строки
  string dTmp = cTmp; // Приведение типов происходит по-умолчанию

  // Копируем указатель
  const char* cTmp2 = cTmp;

  // Изменяем размер строки
  string str5 = "abcd";
  str5.resize(3);
  cout << "str5 = \"" << str5 << "\"" << endl;

  /// boost string - большая библиотека с самыми разными функцями работы со строками

  str5 = "123456789\r\n";
  // В строке: "123456789"
  int pos = str5.find('\r');
  cout << "pos = " << pos << endl;
  cout << "str5.find(\"89\") = " << str5.find("89") << endl;

  // Сравнение строк
  string str6 = "123456789\r\n  89\r\n";
  string str6_1 = str6.substr(str6.find("89\r"), 4);
  string str7 = "89\r\n";
  if(str6.substr(str6.find("89\r"), 4) == str7)
    cout << "str7 found" << endl;

  str6 = "123456789";
  cout << "\"" << str6 << "\"" << endl;
  char buf[10] = {0};
  str6.copy((char*)str6.c_str(), 3, 2);
  cout << "\"" << str6 << "\"" << endl;


  return 0;
}
