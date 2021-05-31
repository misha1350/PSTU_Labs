/*
Вариант  9 (19)

Задача 1: (3, 4, 13)
Контейнер - set
Тип элементов - int

Задача 2:
Тип элементов Money из 18.3

Задача 3:
Параметризированный класс из 18.7
Найти максимальный элемент и добавить его в конец контейнера.
*/

#include <iostream>
#include <set>
#include "Headers 6-13/money13.h"

using namespace std;

typedef set <int> Tset;
set<int>::iterator it;
typedef set<money> Tset2;
typedef Tset2::iterator it2;

Tset s;
int n;

void print_set(Tset s) {
  cout << "\nУпорядоченное дерево set: ";
  for (it = s.begin(); it != s.end(); it++) {
    cout << *it << ", ";
  }
  cout << endl;
}
void print_set1(Tset s1) {
  cout << "\nУпорядоченное дерево set: ";
  for (it = s1.begin(); it != s1.end(); it++) {
    cout << *it << ", ";
  }
  cout << endl;
}
void print_set3(Tset s2) {
  cout << "\nУпорядоченное дерево set: ";
  for (it = s2.begin(); it != s2.end(); it++) {
    cout << *it << ", ";
  }
  cout << endl;
}

Tset Make_set(int n) {
  int a;
  cout << "\nВведите разные значения: ";
  for (int i = 0; i < n; i++) {
      cout << "?";
      cin >> a;
      s.insert(a);
  }
  return s;
}


void c1() {
  cout << "\nМакс. элемент добавлен. (на самом деле нет, т.к. все значения в set могут быть только уникальными)";
  print_set(s);
}

Tset2 Make_set2(int n) {
  money a;
  Tset2 s2;
  int tmp = 0;
  cout << "\nВведите разные значения: ";
  for (int i = 0; i < n; i++) {
    cin >> a;
    s2.insert(a);
  }
  return s2;
}
void c2() {
  int k;
  cout << "\nЭлемент? ";
  cin >> k;
  it = s.find(k);
  if (it != s.end()) {
    s.erase(k);
    cout << "\nЭлемент " << k << " найден и удалён";
    print_set(s);
  }
  else {
    cout << "\nЭлемент не найден!";
  }
}

void c3() {
  Tset s1;
  double avg = 0;
  double upd = 0;
	for (it = s.begin(); it != s.end(); it++)
		avg += *it;
  avg = avg / n;
  cout << "\nСреднее арифметическое элементов контейнера: " << avg;
	int n = s.size(); 
  for (it = s.begin(); it != s.end(); it++)
  {
    upd = avg + *it;
    s1.insert(upd);
  }
  s = s1;
  print_set(s);
}

int main()
{
  setlocale (LC_ALL, "ru");
  int ch;

  cout << "\n1. Автоматическое заполнение\n2. Ручное заполнение set? ";
  cin >> ch;
  if (ch == 1) {
    cout << "\nДобавление случайных значений: " << endl;
    n = 10;
    for (int i = 0; i < 10; i++) {
      int random = rand() % 20 + 1;
      s.insert(random);
      cout << i + 1 << ") " << random << endl;
    }
  }
  else {
    cout << "\nРазмер set?";
    cin >> n;
    Make_set(n);
  }
  print_set(s);

  int c = -1;
  while (c != 0) {
    cout << "\n\nНомер задачи:"
    << "\n\t1. Найти макс. элемент и добавить в конец контейнера\n\t2. Найти элемент с заданным ключом и удалить\n\t3. К каждому элементу добавить среднее арифм. элементов\n\t4. Вывод дерева set\n";
    cin >> c;
    switch (c)
    {
      case 1:
      {
          c1();
      }
      break;
      case 2:
      {
          c2();
      }
      break;
      case 3:
      {
          c3();
      }
      break;
      case 4:
      {
          print_set(s);
      }
      break;
      default:
        if (c != 0)
          cout << "Неправильная команда!";
        break;
    }
  }
  return 0;
}
