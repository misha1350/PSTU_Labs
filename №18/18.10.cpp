/*
Вариант 9 (19):
Создать класс Мопеу для работы с денежными суммами. Число должно быть представлено двумя полями: типа 1оп для рублей и типа т1 для копеек. Дробная часть числа при выводе на экран должна быть отделена от целой части запятой. Реализовать:
-	вычитание дробного числа из суммы
-	операции сравнения (==, !=).
Задание:
•	Удалить все записи равные заданному значению.
•	Уменьшить все записи с заданным значением на 1 рубль 50 копеек. Значение интервала не должно быть меньше 0 рублей 0 копеек.
•	Добавить К записей после элемента с заданным значением.
*/
#include "Headers 6-13/money10.h"
#include "Headers 6-13/file_work.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  money t;
  char file_name[30];
  int k, c;
  do {
    cout << "\n1. Make file";
    cout << "\n2. Print file";
    cout << "\n0. Exit\n";
    cin >> c;
    switch (c) {
      case 1:
        cout << "\n\tFile name? "; cin >> file_name;
        k = make_file(file_name);
        if (k < 0) cout << "\nCan't make file";
        break;
      case 2:
        cout << "\n\tFile name? "; cin >> file_name;
        k = print_file(file_name);
        if (k == 0) cout << "\nEmpty file";
        if (k < 0) cout << "\nCan't read file";
        break;
    }
  }
  while (c!=0);
return 0;
}
