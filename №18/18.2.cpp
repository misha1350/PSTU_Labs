#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

/*
������� 9 (19)
���������������� ����� ���������. ��� - string, ��������� - string, �������� - double.
*/

employee hire_employee()
{
	string d;
	string e;
	double f;
	cout << "��� ���������� - "; cin >> d;
	cout << "��������� ���������� - "; cin >> e;
	cout << "�������� ���������� - "; cin >> f;
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
	employee t1; //����������� ��� ����������
	t1.print();
	employee t2("������", "��������", 60000);
	t2.print();
	employee t3 = t2;
	t3.set_FullName("��������");
	t3.set_Occupation("�������� ���������� ������");
	t3.set_Salary(90000);
	print_employee(t3);
	t1 = hire_employee();
	t1.print();

	return 0;
}