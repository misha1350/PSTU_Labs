#pragma once
#include <iostream>
#include <string>
using namespace std;

class employee
{
	string FullName;
	string Occupation;
	double Salary;
public:
	employee();
	employee(string, string, double);
	employee(const employee&);
	~employee();
	string get_FullName();
	void set_FullName(string);
	string get_Occupation();
	void set_Occupation(string);
	double get_Salary();
	void set_Salary(double);
	void print();
};

/*
Вариант 9 (19)
Пользовательский класс Сотрудник. ФИО - string, должность - string, зарплата - double.
*/

