/*
19. Тип информационного поля char*.
Добавить в список элементы с номерами 1, 3, 5 и т. д.
*/

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

list<char> node;

void make(int size)
{
  char temp;
  for (int i = 0; i < size; i++)
  {
    cout << "\nВведите " << i+1 << " элемент:\t";
    cin >> temp;
    node.push_back(temp); //Вводим элемент в список с конца
  }
}

void add_1_3_5(int size)
{
   int add_element = size; 
   int adv = 1, No = 1;
   list<char>::iterator point_iter;
   point_iter=node.begin();
   char temp;
   for (int i = 0; i < add_element; i++)
   {
     cout << "\nВведите добавляемый элемент №" << No << ";\t";
     cin >> temp;
     node.insert(point_iter, temp);
     advance(point_iter, adv);
     No+=2;
   }
}

int main()
{
  setlocale (LC_ALL, "ru");
  int size;
  cout << "Введите размер списка:\t";
  cin >> size;
  make(size);
  cout << "\nВаш список:\n";
  copy(node.begin(), node.end(), ostream_iterator<char>(cout, " "));
  cout << endl;

  add_1_3_5(size);
  cout << "\nСписок после добавления:\n";
  copy(node.begin(), node.end(), ostream_iterator<char>(cout, " "));

  return 0;
}
