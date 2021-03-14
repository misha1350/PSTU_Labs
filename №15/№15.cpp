/*
Выполнить сортировки методом Шелла и методом Хоара в соответствии со своим вариантом.

19. Дан список рек и их длины. Упорядочить по убыванию длин
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct list
{
  string river;
  int river_length;
};

void fill_out(vector<list>& river_systems, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "\nВведите название реки №" << i+1 << ":\t";
    cin.ignore();
    getline(cin, river_systems[i].river);
    cout << "Введите длину реки №"  << i+1 << " целым числом в километрах:\t";
    cin >> river_systems[i].river_length;
  }
}

void Shellsort(vector<list>& river_systems, int n)
{
  string temp1;
  int temp2, j;
  for (int step = n /2; step > 0; step /= 2)
  {
    for (int i = step; i < n; i++)
    {
      temp1 = river_systems[i].river;
      temp2 = river_systems[i].river_length;
      for (j = i; j >= step; j -= step)
      {
        if (temp2 > river_systems[j - step].river_length)
        {
          river_systems[j].river = river_systems[j - step].river;
          river_systems[j].river_length = river_systems[j - step].river_length;
        }
        else
        {
          break; //потом поменять на j = step
        }
      }
      river_systems[j].river = temp1;
      river_systems[j].river_length = temp2;
    }
  }
}

int main()
{
  int n = 0;
  while (n < 1)
  { 
    cout << "\nВведите кол-во элементов списка:\t";
    cin >> n;
  }
  vector<list> river_systems(n);

  fill_out (river_systems, n);

  cout << "Каким методом сортировать (длины рек по убыванию)?\n\t1.Методом Шелла\n\t2.Методом Хоара\n";
  int choice;
  cin >> choice;

  switch (choice)
  {
    case 1:
    {
      Shellsort(river_systems, n);
      cout << "\n\nРезультат:";
      for (int i = 0; i < n; i++)
      {
        cout << "\n\n" << i+1 << ".\nНазвание реки:\t" << river_systems[i].river << "\nДлина реки:\t\t" << river_systems[i].river_length;
      }
      break;
    }
    case 2:
    {
      cout << "\n done";
      break;
    }
    default:
    { cout << "\n done2"; break;}
  }
  return 0;
}
