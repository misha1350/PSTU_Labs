/*
Вариант  9 (19)


Задача 1: (3, 4, 13)
Контейнер - двунаправленная очередь
Тип элементов - int

Задача 2:
Тип элементов Money из 18.3

Задача 3:
Параметризированный класс из 18.7
Найти максимальный элемент и добавить его в конец контейнера.

Задача 4:
Адаптер контейнера - стек
Найти элемент с заданным ключом и удалить его из контейнера.

Задача 5:
Параметризированный класс - Вектор
Адаптер контейнера - стек
К каждому элементу добавить среднее арифметическое элементов контейнера.
*/

#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include "Headers 6-13/array7.h"
#include "Headers 6-13/money11.h" //18.3
#include "Headers 6-13/vector11.5.h"

template <typename T>

void print(deque<T> dq)
{
      for (int i = 0; i < dq.size(); i++) {
      cout << dq[i] << ", ";
    }
    cout << "\n";
}

int size2;

void c1()
{
  deque <int> dq;
  int n;
    cout << "Размер очереди? "; cin >> n;
    for (int i = 0; i < n; i++) {
      dq.push_back(rand() % 30);
    }
    print(dq);
    dq.pop_back();
    dq.pop_front();
    cout << "Удалены первый и последний элементы. Очередь: ";
    print(dq);
}
void c2()
{
  money d, e;
  cin >> d; cin >> e;
  deque <money> money_dq;
  money_dq.push_back(d);
  money_dq.push_back(e);
  print(money_dq);
  money mean = d + e;
  cout << mean << endl;
  mean = mean/d;
  cout << mean << endl;
  money_dq.push_back(mean);
  print(money_dq);
  money_dq.pop_front();
  cout << "Удалён первый элемент. Очередь: ";
  print(money_dq);
}

void max(Array<money> &arr)
{
  double value_max = 0.0;
  double t4 = 0.0;
  int t2, t3;
  for (int i = 0; i < size2; i++) {
    t2 = arr[i].get_ruble();
    t3 = arr[i].get_kopeck();
    // cout << t2 << t3 << endl;
    t4 = 0.0 + t2 + (t3*0.01);
    cout << t4 << endl;
    if (value_max < t4) {
      value_max = t4;
    }
    t4 = 0.0;
    // if (value_max < arr[i]) {
    //   value_max = arr[i];
  }
  // return value_max;
}

void c3()
{
  money t;
  cin >> t;
  cout << t << endl;

  cout << "size2? "; cin >> size2;
  // cout << "size2? "; cin >> size2;

  Array<money> arr(size2, t);
  cin >> arr;
  cout << arr << endl;
  max(arr);
  // double value_max = max(arr);
}

void c4() {
  stack <int> s;
  cout << "Введите 5 чисел:";
  for (int i = 1; i <= 5; i++) {
    int a;
    cin >> a;
    s.push(a);
  }
  if (s.empty()) cout << "Стек пуст";
  stack <int> temp; int b = -1;
  cout << "Введите номер элемента для удаления (№1 - последний) ";
  while (b < 1 || b > 5) {
    cin >> b;
    if (b < 1 || b > 5) cout << "Неправильное число!";
  }
  for (int i = 1; i < b; i++) {
    temp.push(s.top());
    s.pop();
  }
  s.pop();
  for (int i = b + 1; i <= 5; i++) {
    temp.push(s.top());
    s.pop();
  }
  cout << "Новый стек: ";
  for (int i = 1; i <= 4; i++) {
    cout << temp.top();
    s.push(temp.top());
    temp.pop();
  }
}

void c5() {
  int size;
  cout << "Размер стека? "; cin >> size;
  vector5<int> v (size);
  v.Print();
  int mean = v.find_mean();
  v = v + mean;
  cout << "Среднее арифметическое: " << mean;
  cout << "\nИзменённый стек: ";
  v.Print();
}

int main()
{
  setlocale(LC_ALL, "ru");
  int c = -1;
  while (c != 0) {
        cout << "\n\nНомер задачи:"
            << "\n\t1. Двунаправленная очередь \n\t2. Тип Money (18.3) \n\t3. Параметризированный класс - Вектор (18.7) \n\t4. Адаптер контейнера - стек \n\t5. 3 и 4 \n\t0. Стоп\n: ";
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
            c4();
        }
        break;
        case 5:
        {
            c5();
        }
        break;
        default:
            if (c != 0)
                cout << "ERROR!";
            break;
        }
    }
    return 0;
}
