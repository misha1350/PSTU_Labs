#include <iostream>
#include "employee.h"
#include <string>

using namespace std;

employee::employee()
{
	FullName = "";
	Occupation = "";
	Salary = 0;
	cout << "����������� ��� ���������� ��� �������" << this << endl;
}
employee::employee(string a, string b, double c)
{
	FullName = a;
	Occupation = b;
	Salary = c;
	cout << "����������� � ����������� ��� �������" << this << endl;
}
employee::employee(const employee &t)
{
	FullName = t.FullName;
	Occupation = t.Occupation;
	Salary = t.Salary;
	cout << "����������� ����������� ��� �������" << this << endl;
}
employee::~employee()
{
	cout << "���������� ��� �������" << this << endl;
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
	cout << "���: " << FullName << endl;
	cout << "���������: " << Occupation << endl;
	cout << "��������: " << Salary << endl;
}