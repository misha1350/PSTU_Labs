/*
19.
	Сформировать массив строк. Удалить из него строку, начинающуюся и заканчивающуюся на букву "а".
*/

#include <iostream>
#include <string>

using namespace std;


int find(string *arr, int size)
{
  for (int i = size-1; i >= 0; i--) //От конца до начала массива
	{
	  if ((arr[i][0] == 'a' || arr[i][0] == 'A') && (arr[i][arr[i].length()-1] == 'a' || arr[i][arr[i].length()-1] == 'A')) 
		//Если первый символ = "а" и символ в позиции кол-во байтов в строке (1 байт = 1 латинский символ в кодировке UTF-8) - 1, т.е. последний символ в строке = "а":
		{  
		  for (int l = i; l < size - 1; l++)
			{
			  arr[l] = arr[l + 1];
			}
			size--;
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
		cout  << "Введите строку на англ. раскладке №" << i + 1 << ":\t";
		getline(cin, arr[i]);
	}

size = find(arr, size);

	cout << "\nМассив после удаления: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
	delete[]arr;
	return 0;
}
