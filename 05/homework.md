Домашняя работа (массивы + динамическая память)
===============================================

Максимальный элемент
--------------------
Вывести максимальный элемент одномерного массива целых чисел,
количество элементов которого N пользователь вводит с клавиатуры.
Для массива испольуйте динамическую память.
``` cpp
int N; // Количество элементов массива
cout << "N = ";
cin >> N;
int* A = new int[N];
```

Среднее арифметическое
----------------------
Пользователь вводит натуральное число N - количество действительных (double) чисел в массиве.
Затем в цикле вводит сами числа.
Вычислить среднее арифметическое последовательности и вывести на экран.
``` cpp
int N; // Количество элементов массива
cout << "N = ";
cin >> N;
double* A = new double[N];
...
delete[] A;
```

Среднее арифметическое 2
------------------------
Пользователь вводит натуральное число N - количество действительных чисел в массиве.
Вычислить среднее арифметическое последовательности из N чисел,
без учета минимального и максимального элементов (например, если N = 8,
среднее арифметическое вычисляется для 8 элементов).

Сортировка массива
------------------
Пользователь вводит натуральное число N - количество действительных чисел в массиве.
Затем в цикле вводит сами числа.
Отсортировать массив и вывести отсортированный массив на на экран.

Удалить в массиве числа, повторяющиеся более двух раз
-----------------------------------------------------
Пользователь вводит натуральное число N - количество целых чисел в массиве.
Затем в цикле вводит сами числа.
