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
		cout << "\nНазвание:\t" << name << "\nРежиссёр:\t" << director << "\nСтрана:\t\t" << country << "\nКассовые Сборы:\t" << box_office_$M << endl;
	}
};

void movie(film_info*& film, int N)
{
	setlocale(LC_ALL, "ru");
	for (int i = 0; i < N; i++)
	{
		cin.ignore();
		cout << endl << "\nВведите название фильма №" << i + 1 << ": ";
		getline(cin, film[i].name);
		cout << "\nВведите ФИ режиссёра: ";
		getline(cin, film[i].director);
		cout << "\nВведите страну: ";
		getline(cin, film[i].country);
		cout << endl << "Введите общие кассовые сборы в миллионах долларов: ";
		cin >> film[i].box_office_$M;
	}
}

void erase(film_info*& film, film_info*& film_erase, int& N)
{
	for (int i = 0; i < N - 2; i++) // Цикл удаления элемента с конца совершится два раза
	{
		film_erase[i].name = film[i].name;
		film_erase[i].director = film[i].director;
		film_erase[i].country = film[i].country;
		film_erase[i].box_office_$M = film[i].box_office_$M;
	}
	cout << "\n\n" << "Удалены два фильма в конце списка. Новый список:\n";
	for (int i = 0; i < N - 2; i++)
	{
		film_erase[i].Print();
		cout << "\n";
	}
	int Na;
	Na = N - 2;
}

void add(film_info*& film_erase, film_info*& film_add, int& N, int& Na)
{
	bool target_number = 0;
	string target_name;
	cout << "\n\nВведите название фильма, после которого надо добавить элемент: ";
	cin >> target_name;
	for (int i = 0; i < N; i++)
	{
		if (film_erase[i].name == target_name)
		{
			target_number = true;
			for (int j = 0; j <= i; j++) // В новый третий массив записываются все значения до нового добавленного элемента
			{
				film_add[j].name = film_erase[j].name;
				film_add[j].director = film_erase[j].director;
				film_add[j].country = film_erase[j].country;
				film_add[j].box_office_$M = film_erase[j].box_office_$M;
			}
			cout << "\n\nВведите данные нового фильма.";
			cin.ignore();
			cout << endl << "Введите название фильма №" << i + 2 << ": ";
			getline(cin, film_add[i+1].name);
			cout << "\nВведите ФИ режиссёра: ";
			getline(cin, film_add[i+1].director);
			cout << "\nВведите страну: ";
			getline(cin, film_add[i+1].country);
			cout << endl << "Введите общие кассовые сборы в миллионах долларов: ";
			cin >> film_add[i+1].box_office_$M;
			for (int l = i + 2; l < Na + 1; l++)
			{
				film_add[l].name = film_erase[l - 1].name;
				film_add[l].director = film_erase[l - 1].director;
				film_add[l].country = film_erase[l - 1].country;
				film_add[l].box_office_$M = film_erase[l - 1].box_office_$M;
			}
		}
	}
	if (target_number == 0)
	{
		cout << "\nНазвание не найдено.\n";
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int N, target_number{};
	cout << "Введите количество элементов (фильмов): ";
	cin >> N;
	int Na = N - 2;
	cout << Na;
	film_info* film = new film_info[N];
	film_info* film_erase = new film_info[N - 2];
	film_info* film_add = new film_info[Na + 1];
	movie(film, N);
	erase(film, film_erase, N);
	delete[] film;
	add(film_erase, film_add, N, Na);

	if (film_add[0].name != "")
	{
		cout << "\n\nСписок с добавленным элементом:\n";
		for (int i = 0; i < Na + 1; i++)
		{
			film_add[i].Print();
			cout << "\n";
		}
	}
	else
	{
		cout << "\nДобавить невозможно!\n";
	}
	delete[] film_erase;
	delete[] film_add;
	return 0;
}
