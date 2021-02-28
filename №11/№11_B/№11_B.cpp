#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
19.
B) Стек: Тип информационного поля int. Удалить из стека первый элемент с четным информационным полем.
*/

void print(stack<int> e)
{
  int size = e.size();
  if (size == 0)
  {
    cout << "\nПусто";
  }
  else for (int i = 0; i < size; i++)
  {
    cout << e.top() << "\n";
    e.pop();
  }
}

/*void take_out(stack<int> e, int size, int n)
{

}
*/
int main()
{
  setlocale (LC_ALL, "ru");
  stack<int> e;
  int n = 0, data, size;
  while (n <= 0)
  {
    cout << "Введите кол-во элементов стека:\t";
    cin >> n;
    if (n <= 0)
    {
      cout << "Неправильное значение. В стеке должен быть как минимум 1 элемент.";
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << "Поставьте элемент №" << i+1 << ":\t";
    cin >> data;
    e.push(data);
  }
  cout << "Стек:\n";
  print(e);

  int arr[n], temp;
  bool flag = 0;
  for (int i = 0; i < n; i++)
  {
    arr[i] = e.top();
    e.pop();
  }
  for (int i = 0; i < n; i++)
  {
    if (arr[i] % 2 == 0 && flag != true)
    {
      for (int j = i; j < n-1; j++)
      {
        arr[j] = arr[j+1];
      }
      n--;
      flag = true;
    }
  }
  for (int l = n; l >= 0; l--)
    {
      e.push(arr[l]);
    }

  cout << "\nСтек после удаления:\n";

  for (int i = 0; i < n; i++)
  {
    cout << e.top() << "\n";
    e.pop();
  }
  return 0;
}
