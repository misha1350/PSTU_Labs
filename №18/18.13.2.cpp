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
#include "Headers 6-13/array13.h"

using namespace std;

typedef Array<money> Tarr;
typedef deque <money> Tvec;
money s;
bool f1, f2;

Tarr make_arr (Tvec v, int n) {
  Tarr arr(n, s);
  cout << "make_arr: n = " << n << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << ", ";
  cout << endl;
  for (int i = 0; i < n; i++) {
    arr[i] = v[i];
  }
  return arr;
}

// Tvec make_vector(int n) {
//   Tvec v;
//   for (int i = 0; i < n; i++) {
//     v.push_back(s);
//   }
//   return v;
// }

struct add_mean 
{
	money operator()( money& k) 
	{
		return k += s;
	}
};

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

money srednee(Tarr arr3, Tvec v, int n)
{
	money s = arr3[0];
	for (int i = 1; i < n; i++) {
		s = s + arr3[i];
  }
	return s / n;
}

void print_arr(Tarr arr, int n) {
  // cout << arr << ", "; cout << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << ", ";
  cout << endl;
}

Tvec copy_to_deque(Tarr arr, Tvec v, int n) {
  	Tvec m;
    for (int i = 0; i < n; i++) {
		m.push_back(arr[i]);
	}
	return m;
}

void c1(Tarr arr, Tvec v, int n) {
  Tvec::iterator it;
  it = max_element(v.begin(), v.end());
  cout << "\nМаксимальный элемент: " << *it << endl;
  money add = *it;
  v.push_back(add);
  n = v.size();
  arr = make_arr(v, n);
  cout << "n = " << n << endl;
  // Tarr arr2(n+1, s);
  // for (int i = 0; i < n; i++) {
  //   arr[i] = v[i];
  // }
  print_arr(arr, n);
}

void c2(Tarr arr, Tvec v, int n) {
  cout << "\nЭлемент? ";
  cin >> s;
  remove(v.begin(), v.end(), s);
  cout << "\nЭлемент " << s << " найден и удалён\n";
  n = v.size();
  cout << "n = " << n << endl;
  arr = make_arr(v, n);
  // for(int i = 0; i < n; i++) {
  //   arr[i] = v[i];
  // }
  print_arr(arr, n);
}

void c3(Tarr arr, Tvec v, int n) {
  s = srednee(arr, v, n);
  for_each(v.begin(), v.end(), add_mean());
  cout << "\nСреднее число: " << s << ", новый вектор:\n";
  n = v.size();
  cout << "n = " << n << endl;
  arr = make_arr(v, n);
  // for (int i = 0; i < n; i++) {
  //   arr[i] = v[i];
  // }
  print_arr(arr, n);
}

int main()
{
  setlocale (LC_ALL, "ru");
  cout << "Размер? ";
  int n;
  cin >> n;
  cout << "Введите значения:" << endl;
  Tarr arr(n, s);
  cin >> arr;
  Tvec v;
  v = copy_to_deque(arr, v, n);
  arr = make_arr(v, n);
  cout << arr << endl;
  // n = n + 1;
  c1(arr, v, n);
  // n = n - 1;
  c2(arr, v, n);
  c3(arr, v, n);
  return 0;
}
