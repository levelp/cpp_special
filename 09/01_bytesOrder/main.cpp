/// Порядок байт
/// ============
/// * От старшего к младшему или (big-endian, тупоконечный) - СЕТЕВОЙ
/// Этот порядок является стандартным для протоколов TCP/IP,
/// он используется в заголовках пакетов данных и
/// во многих протоколах более высокого уровня, разработанных для использования поверх TCP/IP.
/// Поэтому, порядок байтов от старшего к младшему часто называют сетевым порядком байтов
/// (network byte order).
/// Используется процессорами IBM 360/370/390, Motorola 68000, SPARC (отсюда третье название — порядок байтов Motorola, Motorola byte order).
/// Порядок байтов от старшего к младшему применяется во многих форматах файлов — например, PNG, FLV, EBML.
/// * От младшего к старшему (little-endian, остроконечный) - ЛОКАЛЬНЫЙ
/// Используется: Intel, x86-процессоры
/// Удобен: сложение последовательно начинается с младшего байта и перенос идёт в старший и т.д.
#include <iostream>
#include <windows.h>

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

class ClassName1 {
  // ... *1*
};

struct ClassName2 {
 private:
  // ... *1*
};

/// Список инициализации
/// --------------------
class User1 {
  // Логин и пароль храним для каждого пользователя
  string login;
  string password;
 public:
  // Поля login и password называются так же,
  // как и параметры конструктора
  // Область видимости у них разная
  User1(string login, string password) {
    // Если мы напишем:
    login = login;
    // то ничего не произойдёт, потому что и слева от = и справа
    // локальная переменная - параметр метода.
    // Как тогда присвоить значение полю?
    this->login = login;
    this->password = password;
  }
};

class User2 {
  // Логин и пароль храним для каждого пользователя
  string login;
  string password;
 public:
  // Второй способ, мы можем переименовать переменные
  User2(string _login, string _password) {
    login = _login;
    password = _password;
  }
};

class User3 {
  // Логин и пароль храним для каждого пользователя
  string login;
  string password;
 public:
  // Поля login и password называются так же,
  // как и параметры конструктора
  // Область видимости у них разная
  // Третий способ: использование списка инициализации
  User3(string login, string password)
    : login(login), password(password) { // Список инициализации
    // В теле конструктора при этом ничего писать не надо
  }
};

// Объединение для конвертации размера файла
union FileSizeConvert {
  // size занимает 8 байт
  unsigned long long size; // 8 байт
  // Структура тоже занимает 8 байт и перекрывает его
  struct {
    DWORD low;  // Первые 4 байта
    DWORD high; // Следующие 4 байта
  };
  // Массив тоже занимает 8 байт и перекрывает и структуру и size
  DWORD data[2]; // Альтернативный вариант
};

// | size                          |
// ---------------------------------
// | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
// ---------------------------------
// |  low          |  high         |

union XYU {
  // x и y будут записываться друг на друга
  int x;
  int y;
};

struct XY {
  int x;
  int y;
};

union IP {
  unsigned char data[4];
  int int_IP;
  unsigned int unsigned_IP;
};

int main() {
  DWORD high = 1;
  DWORD low = 3;

  int DWORD_size_in_bits = 4 * 8; // 32 бита
  unsigned long long fileSize = ((unsigned long long)
                                 high << DWORD_size_in_bits) + low;

  cout << "Size: " << fileSize << endl;

  cout << "High: ";
  showBits(high, sizeof(high));
  cout << "Low:  ";
  showBits(low, sizeof(low));
  cout << "Size: ";
  showBits(fileSize, sizeof(fileSize));

  FileSizeConvert fsc;
  fsc.low = low;
  fsc.high = high;
  cout << "fsc.size = " << fsc.size << endl;

  IP ip;
  // 192.0.2.235
  ip.data[0] = 235;
  ip.data[1] = 2;
  ip.data[2] = 0;
  ip.data[3] = 192;
  cout << "ip.int_IP = " << ip.int_IP << endl;
  cout << "ip.unsigned_IP = " << ip.unsigned_IP << endl;

  /// uint32_t htonl(uint32_t hostlong);
  /// конвертирует 32-битную беззнаковую величину из локального
  /// порядка байтов в сетевой
  htonl()

  /// uint16_t htons(uint16_t hostshort);
  /// конвертирует 16-битную беззнаковую величину из локального порядка байтов в сетевой;
  /// uint32_t ntohl(uint32_t netlong); — конвертирует 32-битную беззнаковую величину из сетевого порядка байтов в локальный;
  /// uint16_t ntohs(uint16_t netshort); — конвертирует 16-битную беззнаковую величину из сетевого порядка байтов в локальный.

  return 0;
}
