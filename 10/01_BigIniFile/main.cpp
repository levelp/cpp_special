#include <iostream>
#include <fstream>
#include <windows.h>
#include <map>
#include <vector>

using namespace std;

/// Настройки приложения
// Использование класса map (стандартный)
// map< типКлюча, типЗначения >
//  Подвиды: treemap (дерево поиска) / hashmap (хеш-таблица)

typedef map<string, string> Section; // key => value
typedef map<string, Section> IniFileData; // sectionName => Section

class Settings {
  // имяСекции -> самаСекция
  IniFileData data;
 public:
  bool changed = false; // Были ли изменения?

  void readIni(char* fileName) {
    ifstream in(fileName); // Открываю файл, in - имя файловой переменной
    string s; // Буфер для чтения строчки
    string section; // Имя секции
    while(!in.eof()) { // Пока не конец файла
      // Читаем очередную строчку
      getline(in, s);
      // Пропускаем пустые строчки
      if(s.size() == 0)
        continue;
      // Если строчка начинается с '[' и заканчивается на ']',
      // то это имя секции
      if(s[0] == '[' && s[s.size() - 1] == ']') {
        section = s.substr(1, s.size() - 2);
        // cout << "section \"" << section << "\"" << endl;
      } else {
        // Проверяем пары вида Ключ = Значения
        int pos = s.find('=');
        if(pos != string::npos) { // Если мы нашли
          // 01235678
          // key=value
          //  pos = 3
          string key = s.substr(0, pos);
          string value = s.substr(pos + 1); // Когда не указано
          // сколько символов, то копируем до конца
          // cout << key << " = " << value << endl;

          data[section][key] = value;
        }
      }
    }
    in.close(); // Закрываю файл

    changed = false; // Только что прочитали файл
  }

  // Секции будут записаны в файл в алфавитном порядке
  // Потому что внутри map хранится как дерево поиска
  void writeIni(char* fileName) {
    ofstream out(fileName); // Открываю файл, out - имя файловой переменной
    // В C++ 11 можно использовать auto
    for(auto it = data.begin(); it != data.end(); ++it) {
      // first => second
      // key   => value
      string sectionName = it->first;
      Section section = it->second;
      // cout << sectionName << endl; // DEBUG
      out << "[" << sectionName << "]" << endl;

      // Сохраняем содержимое секции
      for(auto itSec = section.begin(); itSec != section.end(); ++itSec)
        out << itSec->first << "=" << itSec->second << endl;
    }
    out.close(); // Закрываю файл

    changed = false;
  }

  string getValue(string section, string key) {
    return data[section][key];
  }

  Section getSection(string section) {
    return data[section];
  }

  // Получить количество секций
  int getSectionCount() {
    return data.size();
  }

  // Добавление/изменение
  void setValue(string section, string key, string value) {
    data[section][key] = value;
    changed = true;
  }

  // Удаление элемента: ключ => значение
  void removeKey(string section, string key) {
    data[section].erase(key);
    changed = true;
  }

  // Удаление секции по имени
  void removeSection(string section) {
    data.erase(section);
    changed = true;
  }

  void showSectionsNames() {
    // Итератор - специальная переменная (экземпляр класса)
    // которая умеет проходить по
    // auto - тип переменной определяется автоматически
    // который возвращает data.begin()
    for(auto it = data.begin(); it != data.end(); ++it)
      cout << it->first << endl;
  }
};


int main() {
  char* fileName = "C:\\example.ini";

  ofstream ofs(fileName); // Внутри работает CreateFile
  for(int i = 0; i < 10000; i++) {
    ofs << "[section" << i << "]" << endl;
    ofs << "key" << i << " = " << "value" << i << endl;
  }
  ofs.close();

  char sectionName[256];
  char keyName[256];
  char value[256];
  for(int i = 10000; i < 10100; i++) {
    // Заполняю имя секции
    sprintf(sectionName, "WinApiSection-%d", i);
    // Заполняю имя ключа
    sprintf(keyName, "key");
    // Заполняю имя секции
    sprintf(value, "value%d", i);

    BOOL result = WritePrivateProfileString(
                    sectionName,
                    keyName,
                    value,
                    fileName
                  );
    if(!result)
      cout << "ERROR: " << endl;
  }

  Settings s;
  s.readIni(fileName);
  //s.showSectionsNames();

  if(s.changed)
    s.writeIni("C:\sample2.ini");

  // Создаём
  Settings* mySettings = new Settings();
  // Читаем из файла
  mySettings->readIni(fileName);

  // Удаляем, при этом удаляется map
  delete mySettings;

  return 0;
}
