WinAPI
======

Венгерская нотация
------------------
https://ru.wikipedia.org/wiki/%D0%92%D0%B5%D0%BD%D0%B3%D0%B5%D1%80%D1%81%D0%BA%D0%B0%D1%8F_%D0%BD%D0%BE%D1%82%D0%B0%D1%86%D0%B8%D1%8F


Базовые префиксы типов данных Win32
-----------------------------------

| Префикс | Описание                            |  C/C++               |
|---------|-------------------------------------|----------------------|
| g_      | префикс для глобальной переменной   |	 
| m_      | префикс для переменной класса       |	 
| c       | константа (префикс для типа)        | const
| l       | длинный (префикс для типа)	        | far, long
| p       | указатель (префикс для типа)        | *
| ch      | char                                | char                  
| b       | байт                                | BYTE, unsinged char
| w       | 16-битное слово (2 байта)           | WORD, unsigned short
| dw      | 32-битное слово (4 байта)           | DWORD, unsigned long
| n,i     | целое                               | int
| flt     | с плавающей точкой                  | float
| dbl	  | с плавающей точкой                  | double
| f       | логическое                          | BOOL
| sz      | ASCIZ строка                        | char[]
| psz     | ASCIZ строка                        | char *
| pcsz    | константа ASCIZ строка              | const char *
| pv      | произвольный указатель              | void *
| ppv	  | указатель на произвольный указатель | void **
| h	  | хендл	                        | HANDLE, void *
| unk     | OLE объект	                        | IUnknown
| punk    | указатель на OLE объект	        | IUnknown *
| disp	  | Automation объект	                | IDispatch
| pdisp   | указатель на Automation объект	| IDispatch 

Общий алгоритм:
---------------
1. Пишем в виде комментариев общую последовательность действий
Т.е. сначала формулируем что нужно сделать, если типовая задача, т.е. её можно найти
в MSDN, записываем подробный план по шагам.
Если не типовая задача - разбиваем на шаги пока шаги не станут типовыми.
2. 



1. Открыть файл, записать в него что-то: CreateFile, Read, Write, Close
2. Запуск программы CreateProcess





Домашняя работа
---------------
1. Открываем файл CreateFile
2. Читаем файл ReadFile



