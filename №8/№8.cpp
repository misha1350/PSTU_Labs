//Всё работает, но код некрасивый, и лишние принты использовались для отладки. Также отсутствует защита от дурака








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

void movie(film_info*& film, int N)
{
	setlocale(LC_ALL, "ru");
	for (int i = 0; i < N; i++)
	{
		cin.ignore();
		cout << endl << "Введите название фильма №" << i + 1 << ": ";
		getline(cin, film[i].name);
		cout << "\nВведите ФИ режиссёра: ";
		getline(cin, film[i].director);
		cout << "\nВведите страну: ";
		getline(cin, film[i].country);
		cout << endl << "Введите общие кассовые сборы в миллионах долларов: ";
		cin >> film[i].box_office_$M;
	}
}

void movie_add(film_info*& film_add, int nadd)
{
	setlocale(LC_ALL, "ru");
		cin.ignore();
		cout << endl << "Введите название фильма: ";
		getline(cin, film_add[nadd].name);
		cout << endl << "Введите ФИ режиссёра: ";
		getline(cin, film_add[nadd].director);
		cout << endl << "Введите страну: ";
		getline(cin, film_add[nadd].country);
		cout << endl << "Введите общие кассовые сборы в миллионах долларов: ";
		cin >> film_add[nadd].box_office_$M;
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
	for (int i = 0; i < N - 2; i++)
	{
		cout << "\n\n";
		film_erase[i].Print();
		cout << "\n";
	}
	int Na;
	Na = N - 2;
}

void add(film_info*& film_erase, film_info*& film_add, film_info*& film, int& N, int& Na) // Выходит за рамки массива
{
	int target_number = 0;
	string target_name;
	cout << "\n\nВведите название фильма, после которого надо добавить элемент: ";
	cin >> target_name;
	for (int i = 0; i < N; i++)
	{
		if (film_erase[i].name == target_name)
		{
			target_number = i;
			for (int j = 0; j <= i; j++) // В новый третий массив записываются все значения до нового добавленного элемента
			{
				film_add[j].name = film_erase[j].name;
				film_add[j].director = film_erase[j].director;
				film_add[j].country = film_erase[j].country;
				film_add[j].box_office_$M = film_erase[j].box_office_$M;
			}
			for (int k = 0; k < Na + 1; k++)
			{
				cout << "\n\n";
				film_add[k].Print();
				cout << "\n";
			}
			cout << "\n\nВведите данные нового фильма.";
			int nadd = target_number + 1;
			movie_add(film, nadd + 1);
			
			for (int k = 0; k < Na + 1; k++)
			{
				cout << "\n\n";
				cout << i;
				film_add[k].Print();
				cout << "\n";
			}
			for (int l = i + 2; l < Na + 1; l++)
			{
				film_add[l].name = film_erase[l].name;
				film_add[l].director = film_erase[l].director;
				film_add[l].country = film_erase[l].country;
				film_add[l].box_office_$M = film_erase[l].box_office_$M;
			}
			i = N;
			for (int k = 0; k < Na + 1; k++)
			{
				cout << i << "\n";
				cout << "\n\n";
				film_add[k].Print();
				cout << "\n";
			}
		}
	}
	if (target_number == 0)
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
	int Na = N - 2;
	cout << Na;
	film_info* film = new film_info[N];
	film_info* film_erase = new film_info[N - 2];
	film_info* film_add = new film_info[Na + 1];
	movie(film, N);
	erase(film, film_erase, N);
	if (N != 0)
	{
		add(film_erase, film_add, film, N, Na);
		for (int i = 0; i < Na + 1; i++)
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
