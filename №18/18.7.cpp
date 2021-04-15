/*
Вариант 9 (19)
Класс-контейнер МНОЖЕСТВО с элементами типа int.
Реализовать операции:
[] - доступа по индексу
!= - проверка на неравенство
< число - принадлежность числа множеству.
Пользовательский класс Money для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей и типа int для копеек. Дробная часть числа при выводе на экран  должна быть отделена от целой запятой.
*/

#include <iostream>
#include "Headers 6-13/array7.h"
#include "Headers 6-13/money7.h"

using namespace std;

int main() {
  setlocale (LC_ALL, "ru");

  money t;
  cin >> t;
  cout << t << endl;

  int size1, size2;
  cout << "size1? "; cin >> size1;
  cout << "size2? "; cin >> size2;

  Array<money> arr(size1, t);
  cin >> arr;
  cout << arr << endl;

  Array<money> d(size2, t);
  cout << d << endl;
  cin >> d;
  cout << d << endl;
  d = arr;
  cout << d << endl;

  cout << arr[2] << endl;
  cout << d[7] << endl; //arr[7]


  return 0;
}
