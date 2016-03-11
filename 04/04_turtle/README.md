<!-- doc.py -->
Черепашка
---------
Дана таблица N строк, M столбцов.
В каждой клетке записано целое число (вводим из текстового файла "turtle.txt").
Черепашка начинает ползти из верней левой клетки (0,0) в нижнюю правую.

Черепашка может ползти только вправо и вниз.
Когда черепашка проползает по клетке, она "съедает" число (прибавляет к своей сумме).
Если в клетке отрицательное число, то она "худеет" на это число.

Черепашка должна выбрать оптимальный маршрут, чтобы набрать максимальную сумму.
Нужно вывести максимальную сумму и сам маршрут (как она будет ползти).
Нарисовать таблицу и обозначить ```*``` где она проползёт.

Пример входных данных:
```
4 3
1    1    6
100  2   10000
100  1    7
3    2    4

Ожидамый результат:
```
.  |   0     |  1     |  2
-- | ------- | ------ | --------
0  |  1   *  |  1     |  6
1  | 100 *   |  2 *   | 10000 *
2  |  100    |  1     |  7    *
3  |  3      |  2     |  4    *

Сумма: 10114
[main.cpp](main.cpp)
