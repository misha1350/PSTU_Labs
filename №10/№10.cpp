/*
19.
	Сформировать массив строк. Удалить из него строку, начинающуюся и заканчивающуюся на букву "а".

1 Ввести размер массива;

2.Сформировать массив с помощью операции new или библиотечных функций malloc (calloc);

3.Заполнить массив (можно с помощью датчика случайных чисел);

4.Выполнить задание варианта, сформировать новый массив(ы)-результат(ы);

5.Напечатать массив(ы)-результат(ы);

6.Удалить динамические массивы с помощью операции delete или библиотечной функции free.
*/

#include <iostream>
#include <string>
using namespace std;



int find(string *arr, int size) //звезду поменять местами
{
  for (int i = 0; i < size; i++)
	{
    for (int j = 0; j < arr[i].length(); j++)
    {
		  if (arr[i][0] == 'a' || arr[i][0] == 'A')
		  {
			  if (arr[i][j] == 'a' || arr[i][j] == 'A')
			  {
				  for (int l = i; l < size - 1; l++)
				  {
					  arr[l] = arr[l + 1];
				  }
				  size--;
			  }
		  }
    }
	}
  return size;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int size, letter = 0;

	cout << "Введите количество элементов массива:\t";
	cin >> size;
	string* arr = new string[size];

	cin.ignore();
	for (int i = 0; i < size; i++)
	{
		cout << "\nВведите строку №" << i + 1 << ":\t";
		getline(cin, arr[i]);
	}

size = find(arr, size);

	cout << "Массив после удаления: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
	delete[]arr;
	return 0;
}
