/*
Вариант 9:
Базовый класс: Тройка чисел (triad)
(first) - int
(second) - int
(third) - int
1. Определить методы изменения полей и сравнения триады.
2. Создать производный класс Time с полями часы, минуты, секунды.
3. Определить полный набор операций сравнения временных промежутков.
*/

#include <iostream>

#include "triad2.h"
#include "object.h"
#include "time2.h"

int main() {
  Time a;
  cin >> a;
  std::cout << a << "\n\n";
  object *p=&a;
  p->show();

  Time b(2021, 3, 21);
  std::cout << "\nComparison to:\n" << b;

  bool comparison = a == b;
  if (comparison == true) std::cout << "\nA == B";
  else std::cout << "\nA != B";

  if (comparison != true) {
    bool greater_than = a > b;
    if (greater_than == true) std::cout << "\nA > B";
    else std::cout << "\nA < B";
  }
  return 0;
}

