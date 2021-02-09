//WIP








#include <iostream>
#include <string>
using namespace std;

/*
19. Структура "Фильм":
- название
- режиссер
- страна
- приносимая прибыль
Удалить 2 элемента из конца файла, добавить элемент после элемента с указанным названием
*/


struct film_info {
	string name, director, country;
	float box_office_$M;

	void Print()
	{
		cout << "Название:\t" << name << "\n"Режиссёр:\t" << director << "\nСтрана:\t" << country << "\nКассовые Сборы:\t" << box_office_$M << endl;
	}
};

void(film_info*& film, int N, k)
{
	setlocale(LC_ALL, "ru");
	for (int i = k; i < N; i++)
	{
		cout << endl << "Введите название фильма: ";
		getline(cin, film[i].name);
		cout << endl << "Введите ФИ режиссёра: ";
		getline(cin, film[i].director);
		cout << endl << "Введите страну: ";
		getline(cin, film[i].country);
		cout << endl << "Введите общие кассовые сборы в миллионах долларов: ";
		cin >> film[i].box_office_$M;
	}
}

void erase(film_info*& film, int)
{
	for (int i = N - 2; i < N; i++)
	{
		film[i].name = film[i + 2].name;
		film[i].director = film[i + 2].director;
		film[i].country = film[i + 2].country;
		film[i].box_office_$M = film[i + 2].box_office_$M;
	}
	N--;
}

int main()
{
	setlocale(LC_ALL, "ru");
	film_info film[5];
	
}
