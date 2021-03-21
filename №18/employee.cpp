#include <iostream>
#include "employee.h"
#include <string>

using namespace std;

employee::employee()
{
	FullName = "";
	Occupation = "";
	Salary = 0;
	cout << "Конструктор без параметров для объекта" << this << endl;
}
employee::employee(string a, string b, double c)
{
	FullName = a;
	Occupation = b;
	Salary = c;
	cout << "Конструктор с параметрами для объекта" << this << endl;
}
employee::employee(const employee &t)
{
	FullName = t.FullName;
	Occupation = t.Occupation;
	Salary = t.Salary;
	cout << "Конструктор копирования для объекта" << this << endl;
}
employee::~employee()
{
	cout << "Деструктор для объекта" << this << endl;
}
string employee::get_FullName()
{
	return FullName;
}
string employee::get_Occupation()
{
	return Occupation;
}
double employee::get_Salary()
{
	return Salary;
}
void employee::set_FullName(string a)
{
	FullName = a;
}
void employee::set_Occupation(string b)
{
	Occupation = b;
}
void employee::set_Salary(double c)
{
	Salary = c;
}
void employee::print()
{
	cout << "ФИО: " << FullName << endl;
	cout << "Должность: " << Occupation << endl;
	cout << "Зарплата: " << Salary << endl;
}