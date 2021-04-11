/*
Вариант 9 (19)

Класс - контейнер МНОЖЕСТВО с элементами типа int.
Реализовать операции:
[] - доступа по индексу;
!= - проверка на неравенство;
< число - принадлежность числа множеству;
+ n - переход вправо к элементу с номером n (с помощью класса-итератора).
*/

#include <iostream>
#include "Headers 6-13/array.h"

using namespace std;

int main()
{
  array arr(5);
  cout << arr << endl;
  cin >> arr;
  cout << arr << endl;

  arr[2] = 50;
  cout << arr << endl;

  bool inequality = arr[2] != arr[4];
  if (inequality == true) {
    std::cout << "\n arr[2] != arr[4],";
    std::cout << "\n\t " << arr[2] << " != "<< arr[4];
  }
  else cout << "\n arr[2] == arr[4]";


  // int n = 100;
  bool belongs = arr < 10;
  if (belongs == true) cout << "\narr < n";
  else cout << "\narr > n";


  cout  << "\n\narr.first = " << *(arr.first()) << ",\narr.last = " << *(arr.last()) << endl;
  iter itr = arr.first();
  
  int n;
  cout << "\nn = ";
  cin >> n;

  itr += n-1;
  cout  << *itr << endl;
}
