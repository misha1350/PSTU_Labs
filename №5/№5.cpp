#include <iostream>
#include<math.h>
#include<string>
using namespace std;

//Задана строка из N^2 цифр. 
//Установить, можно ли, разбив строку на подстроки двумерного массива N * N по одной цифре в одном элементе так, чтобы они в первом столбце расположились в порядке возрастания.

void Foo(int** arr, int x1)
{
	int f=0;
	for (int i = 0; i < x1-1; i++)
	{
		if (arr[i][0]>arr[i+1][0])
		{
			f++;
		}

	}
	switch (f)
	{
	case(0):
	{
		cout << "Возможно разбить строку на равные подстроки так, чтобы элементы в первом столбце расположились в порядке возрастания.";
		break;
	}
	default:
		cout << "Невозможно разбить строку на равные подстроки так, чтобы элементы в первом столбце расположились в порядке возрастания.";
		break;
	}
}

void output(int** arr, int x1)
{
	cout << "\nМассив:\n";
	for (int i = 0; i < x1; i++)
	{
		for (int j = 0; j < x1; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}

}

int main()
{
	int A=0;
	double x1=1, x2=2;
	string str;
	while((x1!=x2||x1==1)&&A==0)
	{
		cout << "Введите строку цифр:";
		getline(cin, str);
		A = str.length();
		if (A==0)
		{
			cout << "Сторка - пуста!\n";
		}
		else
		{
			x1 = sqrt((double)A);
			x2 = (int)sqrt((double)A);
			if (x1 != x2|| x1==1)
			{
				cout << "Невозможно разбить строку на равные подстроки!\n";
			}
		}
	}
	int** arr = new int* [x1];
	for (int i = 0; i < x1; i++)
	{
		arr[i] = new int[x1];
	}
	int No = 0;
	for (int i = 0; i < x1; i++)
	{
		for (int j = 0; j < x1; j++)
		{
			if (str[No] == *"0")
				arr[i][j] = 0;
			if (str[No] == *"1")
				arr[i][j] = 1;
			if (str[No] == *"2")
				arr[i][j] = 2;
			if (str[No] == *"3")
				arr[i][j] = 3;
			if (str[No] == *"4")
				arr[i][j] = 4;
			if (str[No] == *"5")
				arr[i][j] = 5;
			if (str[No] == *"6")
				arr[i][j] = 6;
			if (str[No] == *"7")
				arr[i][j] = 7;
			if (str[No] == *"8")
				arr[i][j] = 8;
			if (str[No] == *"9")
				arr[i][j] = 9;
			No++;
		}
	}
	output(arr, x1);
	Foo(arr, x1);
}
