/*
Вариант  9 (19)

Задача 1: (3, 4, 13)
Контейнер - set
Тип элементов - int

Задача 2:
Тип элементов Money из 18.3

Задача 3:
Параметризированный класс из 18.7
Найти максимальный элемент и добавить его в конец контейнера.
*/

#include <iostream>
#include "Headers 6-13/container12.h"
#include "Headers 6-13/money13.h"
using namespace std;
int SafeInput(bool strict) {
	int result;
	while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите корректное число!" << endl;
	}
	cin.get();
	return result;
}
int main()
{
  setlocale(LC_ALL, "ru");
	srand(time(NULL));
	cout << "Введите количество элементов: ";
	int size = SafeInput(1);
	container<money> Vector(size);
	Vector.show();
	Vector.PushMax();
	Vector.show();
	cout << "Введите ключ для удаления: ";
	money key;
	cin >> key;
	Vector.delKey(key);
	Vector.show();
	Vector.AVG();
	Vector.show();
	return 0;
}
