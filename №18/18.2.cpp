#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

/*
Вариант 9 (19)
Пользовательский класс Сотрудник. ФИО - string, должность - string, зарплата - double.
*/

employee hire_employee()
{
	string d;
	string e;
	double f;
	cout << "ФИО сотрудника - "; cin >> d;
	cout << "Должность сотрудника - "; cin >> e;
	cout << "Зарплата сотрудника - "; cin >> f;
	employee t(d, e, f);
	return t;
}
void print_employee(employee t)
{
	t.print();
}

int main()
{
	setlocale(LC_ALL, "ru");
	employee t1; //Конструктор без параметров
	t1.print();
	employee t2("Иваныч", "Сисадмин", 60000);
	t2.print();
	employee t3 = t2;
	t3.set_FullName("Димдимыч");
	t3.set_Occupation("Директор сервисного центра");
	t3.set_Salary(90000);
	print_employee(t3);
	t1 = hire_employee();
	t1.print();

	return 0;
}
