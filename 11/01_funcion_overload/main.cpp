/// Перегрузка функций
/// ------------------
#include <iostream>
#include <cmath>
#include <cstdio>

#define SHOW(x) cout << #x << " = " << (x) << endl;

using namespace std;

// Пример перегрузки
int min(int a, int b) {
  return (a < b) ? a : b;
}

double min(double a, double b) {
  return (a < b) ? a : b;
}

string min(string s1, string s2) {
  if (s1 < s2)
    return s1;
  else
    return s2;
}

// Шаблон функции
// T - произвольный тип, который поддерживает все необходимые операции
template<class T>
T myMax(T a, T b) {
  return (a > b) ? a : b;
}

void test(int x, int y) {
  cout << "ints: " << (x + y) << endl;
}

void test(string s1, string s2) {
  cout << "strings: " << s1 << " " << s2 << endl;
}

struct Point {
  double x, y;

  // (1*) - эквивалентно записи 2
  // Перегрузка оператора '>'
  // "operator" + ">", "<", ">=", "<=", "==", "+", "-", "*", "/"
  // Сравниваем:
  //  больше ли текущая точка той, с которой мы сравниваем
  // p1 - this - текущая точка
  // p2 - та, с которой сравниваем
  bool operator<(Point& p2) {
    // Сравнивать можно любым методом
    // Конретный метод сравнения определяется задачей
    double distThis = x + y; // Для текущей точки
    double dist = p2.x + p2.y; // Для той точки, с которой сравниваем
    return distThis < dist;
  }

  bool greater(Point& p2) {
    // Сравнивать можно любым методом
    // Конретный метод сравнения определяется задачей
    double distThis = x + y; // Для текущей точки
    double dist = p2.x + p2.y; // Для той точки, с которой сравниваем
    return distThis > dist;
  }
};

// (2*)
// 2 входящих параметра
// Вызов: p1 > p2  заменяется на  operator>(p1, p2)
bool operator>(Point& p1, Point& p2) {
  double dist1 = p1.x + p2.y; // 1-ая точка
  double dist2 = p2.x + p2.y; // 2-ая точка
  return dist1 > dist2;
}

// Перегружаем операцию вывода в поток:
// ostream - поток вывода
// Point p1;
// cout << p1;
// Т.е. мы вызываем: operator<<(cout, p1)
ostream& operator<<(ostream& out, Point& point) {
  out << "(" << point.x << ", " << point.y << ")";
  return out;
}

int main() {
  double distThis = 100;
  SHOW(myMax(10, 20));
  SHOW(myMax('A', 'B'));
  SHOW(myMax(10.312, 213.212));
  SHOW(myMax('t', 'h'));
  string s1("test");
  string s2("hello");
  SHOW(s1 > s2);
  SHOW(myMax(s1, s2));
  Point p1 = {1, 2}; // x = 1, y = 2
  Point p2 = {3, 4}; // x = 3, y = 4
  // Что делать, если в нашем типе данных Point не определена нужная операция '>'
  Point p3 = myMax(p1, p2); // Изначально не определена операция '>'
  // При этом сообщение об ошибке:
  // In instantiation of 'T myMax(T, T) [with T = Point]':
  // error: no match for 'operator>' (operand types are 'Point' and 'Point')
  // return (a > b) ? a : b;
  // Можно определить операцию '>' внутри класса Point
  SHOW(p3.x);
  SHOW(p3.y);
  //  p1 > p2         -- вызов операции
  cout << "p1.greater(p2) = " << p1.greater(p2) << endl;
  // Операции применяются Слева-Направо
  //  Замена: ".greater" => ">"
  cout << "p1.'>'(p2) = " << (p1 > p2) << endl;

  // Кроме того, нужна операция вывода в поток '<<'
  cout << "p1 = " << p1 << endl;
  // operator<<(cout, p1)
  // stdin - поток ввода с консоли
  // stdout - стандартный поток вывода
  // stderr - стандартный поток вывода для ошибок

  // Вызываю 2 различные функции, которые называются одинаково
  test(4, 10);
  test("test1", "test2");

  cout << "TEST" << endl;

  freopen("test.txt", "w", stdout);
  cout << "TEST" << endl;

  // istream is; // Поток ввода
  // ifstream - поток ввода из файла
  // sstream - поток ввода из строчки
  // ostream os; // Поток вывода

  return 0;
}