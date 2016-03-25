/// Структуры и Классы
/// ==================
//
// В современном C++ единственное отличие
// класса от структуры в модификаторе доступа по-умолчанию:
// class - private
// struct - public
// Внутри класса есть Поля и Методы.
// * Поле (как бы "переменная" внутри класса), поле хранит значение.
// * Метод (как бы "функция" внутри класса).
//   - может быть сразу заголовок и реализация внутри класса
//   - может быть реализация потом, далее в коде, с указанием к какому классу она относится
// Модификатор доступа определяет из каких мест программы
// есть доступ к полю или методу класса.
// Модификаторы в порядке увеличения доступа:
// * private - доступ только изнутри этого класса
// * protected - внутри этого класса и его наследников
// * public - доступ из всех мест, где видна переменная - обьект-класса:
// из этого класса, из наследников, из других классов,
// из любого места программы, где объявлен этот класс.
//
// * static - принадлежит классу, а не конкретному объекту (конкретному экземпляру класса).

#include <iostream>

using namespace std;

#define SHOW(x) cout << #x << " = " << x << endl;

// Объявление классов
// class ИмяКласса {
//   описание класса: Поля и Методы
// }
// Внешняя реализация:
// Метод:
// ТипВозвращаемогоЗначения ИмяКласса::имяМетода(параметры) {
//    Реализация метода (операторы... )
// }
// Переменных (только статических):

// Объявление Класса
class Human {
  int id;  // Идентификатор конкретного человека
 public:
  static int count; // Общее поле для всех Human
  // Конструктор
  Human() {
    count++; // Общее поле для всех Human
    id = count; // Присваиваю идентификатор конкретному человеку
    cout << "Human Constructor #" << id << endl;
  }
};

int Human::count = 0;

void f1() {
  cout << "f1 >>>" << endl;
  Human h1;
}

void f2() {
  cout << "f2 >>>" << endl;
  Human h2, h3;
}

void f3() {
  cout << "f3 >>>" << endl;
  Human h[5];
}

// Объявляем класс с одной переменной int
class Test {
  int a1;
};

// Класс с одной переменной и одной функцией описанной внутри
// Описание метода внутри класса
class Test2 {
  int a;
  // Метод - функция
  void func2() {
    // Внутри функции можно использовать переменные (поля)
    a = 10;
  }
};

// Класс с одной переменной и одной функцией описанной внутри
// Описание метода вне класса
class Test3 {
  int a;
  // Объявлем заголовок метода - функция
  void func2(int x);
};

// Реализация метода вне класса - функция
void Test3::func2(int x) {
  // Внутри функции можно использовать переменные (поля)
  a = 10;
}

// При объявлении методов названия параметров можно не указывать
// Обычно находится в .H файле
class Test4 {
  int a;
  // Объявлем заголовок метода - функция
  void func2(int, char);
};

// Реализация метода вне класса - функция
// Обычно находится в .CPP файле
void Test4::func2(int x, char c) {
  // Внутри функции можно использовать переменные (поля)
  a = 10;
}

// Модификаторы доступа
class Shape {
  // По-умолчанию private
  int privateField = 1;
 protected:
  int protectedField = 5;
 public:
  int publicField = 10;
  // Массивы
  int myArray[100];
  int* arrayPtr;
  // И снова можно private
 private:
  int private1 = 1;
  string privateStr = "Test";
};

// Не возвращаем ничего, передаём по значению
// В основной программе НЕ поменятся s1
void funcShape(Shape s1) {
  // Меняем значение поля
  s1.publicField = 100;
}

// Передаём по ссылке
// В основной программе МЕНЯЕТСЯ s1
void funcShape2(Shape& s1) {
  // Меняем значение поля
  s1.publicField = 10;
  s1.myArray[0] = 13;
  s1.arrayPtr[0] = 53;
}

// Передаём по указателю
// В основной программе МЕНЯЕТСЯ s1
void funcShape3(Shape* s1) {
  // Меняем значение поля
  s1->publicField = 10;
  (*s1).publicField = 11;
  // Обращение к элементу массива
  s1->myArray[0] = 13;
  // Самая правильная и каноничная запись
  s1->arrayPtr[0] = 53;
  // Альтернативы
  (*s1).arrayPtr[0] = 53;
  *((*s1).arrayPtr) = 53;
  // Ко второму элементу
  // Смещаем указатель на 1
  *((*s1).arrayPtr + 1) = 53;
  // Создаём указатель на int
  // Записываем в ptr адрес первого элемента arrayPtr
  int* ptr = s1->arrayPtr;
  // Двигаем указатель вперёд, на следующий элемент
  ptr++;
  *ptr = 53;
  ptr++;
  *ptr = 20;
  // "Выстреливаем себе в ногу" - перезаписываем указатель

  s1 = new Shape();
}

// Класс без использования Конструкторов и Деструкторов
class Class1 {
 public:
  void create(); // Инициализация
  void del(); // Очистка памяти
};

// У Конструктора и Деструктора есть специальные "названия"
class Class2 {
  int* myArray;
 public:
  // Конструктор: ИмяКласса
  Class2() {
    // ...
    myArray = new int[1000];
  }
  // Деструктор: ~ИмяКласса
  ~Class2() {
    // ...
    delete[] myArray;
  }
};

// Наследование
// [: ОтКакихКлассовНаследуетсяКласса]
// Объявление класса Животное
class Animal {
 public:
  string name;
};

// Класс Кошка наследует класс Животное
class Cat : public Animal {
 public:
  void say() {

  }
};

// Из функции
void myFunction() {
  Animal a;
  a.name = "Name";
}

// get/set
// Свойство (property)
// Delphi: write / read
class AnimalGetSet {
  string name;
 public:
  void setName(string name) {
    this->name = name;
  }
  string getName() {
    return "[" + name + "]";
  }
};

/// typedef
/// =======
// Метафора, описывающая typedef:
// ------------------------------
// В typedef мы пишем определение как если бы мы объявляли переменную
// только "название переменной" становится именем типа.

// определяем новый тип ulong как unsigned long
typedef unsigned long ulong;

// l1 и l2 имеют одинаковый тип
unsigned long l1;
ulong l2;

// Delphi Record => C/C++ struct
// Указатели
int* intPtrVar; // Объявление переменной указателя на int
typedef int* intPtrTypeName; // тип - указатель на int
intPtrTypeName intPtr2; // intPtr2 тот же тип что и у intPtrVar

// Определение нового типа для массива
int arrayVar[10]; // Переменная - массив из 10 элементов типа int
typedef int arrayTypeName[10]; // "[10]" не входит в название, в название типа входит
// ТОЛЬКО arrayTypeName
// Обе переменные имеют одинаковый тип
arrayTypeName arrayVar2;

int* arrayVarPtr[10]; // Переменная - массив из 10 элементов - указателей на int
typedef int* arrayTypeNamePtr[10]; // "[10]" не входит в название
arrayTypeNamePtr arrayVarPtr2;

// type type1 = Integer;
int var1, var2, *varPtr3;
typedef int type1, type2, *typePtr3;

// functionReference - тип - ссылка на функцию которая возвращает
// int и принимает 2 аргумента с типом int
typedef int (&functionReference)(int, int);

// Функция применяет операцию operation,
// конкретная реализация которой ещё не определена
// a - массив целых чисел (массив уже создан и передаётся в готовом виде)
// size - его размер
int applyToArray(int a[], int size, functionReference operation) {
  int res = a[0];
  for(int i = 1; i < size; i++)
    res = operation(res, a[i]);
  return res;
}

// functionPointer - тип - указатель на функцию которая возвращает
// int и принимает 2 аргумента с типом int
typedef int (*functionPointer)(int, int);

// Функция применяет операцию operation,
// конкретная реализация которой ещё не определена
int applyToArrayPtr(int a[], int size, functionPointer operation) {
  int res = a[0];
  for(int i = 1; i < size; i++)
    res = operation(res, a[i]);
  return res;
}

// Конкретные реализации functionReference
int sum(int a, int b) {
  return a + b;
}

// Multiply - умножение
int mul(int a, int b) {
  return a * b;
}

// Определяем точку и указатель на точку
typedef struct {
  double x, y;
} Point, *pPoint;
Point* pPtr1;
pPoint pPtr2;

// В современном C++ можно написать просто вот так:
struct Point2D {
  double x, y;
};
// Ипсользуем "class" вместо "struct"
class Point2Dx {
 public:
  double x, y;
};

int main() {
  // Вызываем все 3 функции
  f1();
  f2();
  f3();
  cout << "Human.count = " << Human::count << endl;

  Animal a;
  cout << a.name << endl;
  a.name = "Новое имя";

  // Вызов конкретной реализации
  int A[] = {2, 3, 10, 10};
  SHOW(applyToArray(A, 4, sum));
  SHOW(applyToArray(A, 4, mul));
  SHOW(applyToArrayPtr(A, 4, sum));
  SHOW(applyToArrayPtr(A, 4, mul));

  return 0;
}
