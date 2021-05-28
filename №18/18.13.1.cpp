/*
Вариант  9 (19)

Задача 1: (3, 4, 13)
Контейнер - двунаправленная очередь
Тип элементов Money

Задача 2:
Параметризированный класс из 18.7

Задача 3:
Ассоциативный контейнер - множество (set)


Задание 3:
Найти максимальнынй элемент и добавить его на заданную позицию контейнера

Задание 4:
Найти элемент с заданным ключом и удалить его из контейнера

Задание 5:
К каждому элементу добавить среднее арифметическое элементов контейнера
*/

#include <iostream>
#include <algorithm>
#include <deque>
#include "Headers 6-13/money13.h"

using namespace std;

typedef deque <money> Tvec;
Tvec d;
money s;

Tvec make_vector(int n) {
  Tvec v;
  for (int i = 0; i < n; i++) {
    cin >> s;
    v.push_back(s);
  }
  return v;
}

struct add_mean 
{
	money operator()( money& k) 
	{
		return k += s;
	}
};

// struct Greater_s {
//   bool opert
// };

struct Equal_s
{
	bool operator()(money t)
	{
		return t == s;
	}
};
 
struct Greater_s
{
	bool operator()(money t)
	{
		return t > s;
	}
};

money srednee(Tvec v)
{
	money s = v[0];
  // double avg;
	for (int i = 1; i < v.size(); i++) {
		s = s + v[i];
  }
	int n = v.size();
	return s / n;
}

void print_vec(Tvec v) {
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << ", ";
  cout << endl;
}

void c1(Tvec v) {
  Tvec::iterator it;
  it = max_element(v.begin(), v.end());
  cout << "\nМаксимальный элемент: " << *it << endl;
  money add = *it;
  v.push_back(add);
  print_vec(v);
}

void c2(Tvec v) {
  cout << "\nЭлемент? ";
  cin >> s;
  remove(v.begin(), v.end(), s);
  cout << "\nЭлемент " << s << " найден и удалён\n";
  print_vec(v);
}

void c3(Tvec v) {
  s = srednee(v);
  for_each(v.begin(), v.end(), add_mean());
  cout << "\nСреднее число: " << s << ", новый вектор:\n";
  print_vec(v);
}

int main()
{
  setlocale (LC_ALL, "ru");
  int n;
  cout << "Размер? ";
  cin >> n;
  Tvec v;
  v = make_vector(n);
  print_vec(v);

    int c = -1;
  while (c != 0) {
    cout << "\n\nНомер задачи:"
    << "\n\t1. Добавить максимальнынй элемент"
      << "\n\t2. Найти элемент с заданным ключом и удалить"
      << "\n\t3. К каждому элементу добавить среднее арифм. элементов"
      << "\n\t4. Вывод вектора"
      << "\n\t0. Выйти из программы\n";
    cin >> c;
    switch (c)
    {
      case 1:
      {
          c1(v);
      }
      break;
      case 2:
      {
          c2(v);
      }
      break;
      case 3:
      {
          c3(v);
      }
      break;
      case 4:
      {
          print_vec(v);
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

