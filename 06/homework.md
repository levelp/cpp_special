Домашнее задание: реализовать классы геометрических фигур
---------------------------------------------------------

Используем struct вместо class чтобы не писать везде public.

Базовый класс **Фигура**
``` cpp
struct Shape { // struct -> public:
  virtual void show() = 0; // Абстрактный метод
};
```
Квадрат
``` cpp
struct Square : public Shape {
  double side;
  Square(double s) : side(s) { }
  void show() {
    // TODO: реализовать
  }
};
```

Прямоугольник
``` cpp
struct Rectangle : public Shape {
  double height, width;
  Rectangle(double h, double w) :
    height(h), width(w) { }
  void show() {
    // TODO: реализовать
  }
};
```

Добавить Круг (для него задать радиус).

Демонстрационная программа показывающая все фигуры.
Записать в массив указатели на классы всех видов фигур.
Вызывать в цикле метод show() для всех фигур.

``` cpp
int main() {
  Shape* s[] = {
    new Square(10),
    new Rectangle(2, 3),
    new Square(15),
  };

  for(int i = 0; i < 3; ++i)
    s[i]->show();

  return 0;
}
```