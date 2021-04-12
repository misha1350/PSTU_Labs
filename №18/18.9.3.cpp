/*
Вариант 9 (19)
Класс-контейнер МНОЖЕСТВО с элементами типа int.
Реализовать операции:
[] - доступа по индексу
!= - проверка на неравенство
< число - принадлежность числа множеству.
+ n - переход вправо к элементу с номером n.

3, 1
*/

#include "Headers 6-13/error.h"
#include "Headers 6-13/array9.h"
#include <iostream>

using namespace std;

int main() 
{
  try
  {
    array arr(5);
    cout << arr << endl;
    cin >> arr;
    cout << arr << endl;

    cout << "Input numbers:\n";
    int i;
    cin >> i;
    cout << arr[i] << endl;
    
    arr[2] = 50;
    cout << "\nadded 50 in place of arr[2]:\n";
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
  }
  catch (error &e) {
    e.what();
  }
  return 0;
}
