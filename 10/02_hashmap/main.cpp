/// HashMap
/// -------
/// Ассоциативный массив на основе Хеш-таблицы
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  // Создаём набор Ключ => Значение
  unordered_map<string, string> u = {
    {"RED", "#FF0000"},
    {"GREEN", "#00FF00"},
    {"BLUE", "#0000FF"}
  };

  // Пробегаем и печатаем ключи и значения
  for(auto& n : u) {
    auto key = n.first;
    auto value = n.second;
    cout << "Key: " << key << " Value: " << value << endl;
  }

  // Add two new entries to the unordered_map
  u["BLACK"] = "#000000";
  u["WHITE"] = "#FFFFFF";

  // Output values by key
  cout << "The HEX of color RED is: " << u["RED"] << endl;
  cout << "The HEX of color BLACK is: " << u["BLACK"] << endl;

  return 0;
}
