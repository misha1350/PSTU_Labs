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

	void Print() //Починить вывод значений переменных
	{
		cout << "Название:\t" << name << "\nРежиссёр:\t" << director << "\nСтрана:\t" << country << "\nКассовые Сборы : \t" << box_office_$M << endl;
	}
};

void movie(film_info*& film, int N, int k)
{
	setlocale(LC_ALL, "ru");
	for (int i = k; i < N; i++)
	{
		cin.ignore();
		cout << endl << "Введите название фильма №" << i+1 << ": ";
		getline(cin, film[i].name);
		cout << "\nВведите ФИ режиссёра: ";
		getline(cin, film[i].director);
		cout << "\nВведите страну: ";
		getline(cin, film[i].country);
		cout << endl << "Введите общие кассовые сборы в миллионах долларов: ";
		cin >> film[i].box_office_$M;
	}
}

void movie_add(film_info*& film_add, int N, int k)
{
	setlocale(LC_ALL, "ru");
	for (int i = k; i < N; i++)
	{
		cout << endl << "Введите название фильма: ";
		getline(cin, film_add[i].name);
		cout << endl << "Введите ФИ режиссёра: ";
		getline(cin, film_add[i].director);
		cout << endl << "Введите страну: ";
		getline(cin, film_add[i].country);
		cout << endl << "Введите общие кассовые сборы в миллионах долларов: ";
		cin >> film_add[i].box_office_$M;
	}
}

void erase(film_info*& film, int& N) //Сделать ограничение на менее одного элемента - элементов будет вводиться не менее 5
{
	for (int i = N - 2; i < N; i++) // Цикл удаления элемента с конца совершится два раза
	{
		film[i].name = film[i + 2].name;
		film[i].director = film[i + 2].director;
		film[i].country = film[i + 2].country;
		film[i].box_office_$M = film[i + 2].box_office_$M;
	}
	N = N - 2;
}

void add(film_info*& film, film_info*& film_add , int& N) // Выходит за рамки массива
{
	bool f = 0;
	string namesearch;
	cout << "\n\nВведите название фильма, после которого надо добавить элемент: ";
	cin >> namesearch;
	for (int i = 0; i < N; i++)
	{
		if (film[i].name == namesearch)
		{
			f = true;
			for (int j = 0; j < i; j++)
			{
				film_add[j].name = film[j].name;
				film_add[j].director = film[j].director;
				film_add[j].country = film[j].country;
				film_add[j].box_office_$M = film[j].box_office_$M;
			}
			cout << "\n\nВведите данные нового фильма.";
			movie_add(film_add, i + 1, i);
			for (int j = i + 1; j < N + 1; j++)
			{
				film_add[j] = film[j + 1];
			}
			i = N;
		}
	}
	if (f == 0)
	{
		cout << "Название не найдено.\n";
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int N;
		cout << "Введите количество элементов (фильмов): ";
	cin >> N;
	film_info* film = new film_info[N];
	film_info* film_add = new film_info[N + 1];
	movie(film, N, 0);
	// !!!! Вылетает тут: erase(film, N);
	if (N != 0)
	{
		// !!!! Вылетает тут: add(film, film_add, N);
		for (int i = 0; i < N + 1; i++)
		{
			cout << "\n\n";
			film_add[i].Print();
			cout << "\n";
		}
	}
	else
	{
		cout << "\nДобавить невозможно!\n";
	}
	return 0;
}
