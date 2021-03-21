#include <iostream>
#include "money.h"

using namespace std;

/*
������� 9 (19)
��� ���� - long ��� ������ � int ��� ������. ������� ����� ���������� �������. �����������:
- ��������� �������� ����� �� �����
- �������� ��������� (==, !=)
*/

//���������� �������� ������������
money& money::operator=(const money& t)
{
	//�������� �� ����������������
	if (&t == this)
		return *this;
	ruble = t.ruble;
	kopeck = t.kopeck;
	return *this;
}
//���������� ���������� �������� ���������
money& money::operator++()
{
	long temp = ruble * 100 + kopeck;
	temp++;
	ruble = temp / 100;
	kopeck = temp % 100;
	return *this;
}
//���������� ����������� �������� ���������
money money::operator++ (int)
{
	long temp = ruble * 100 + kopeck;
	temp++;
	money t(ruble, kopeck);
	ruble = temp / 100;
	kopeck = temp % 100;
	return t;
}
//���������� �������� �������� ��������
money money::operator+ (const money& t)
{
	long temp1 = ruble * 100 + kopeck;
	long temp2 = t.ruble * 100 + t.kopeck;
	money add;
	add.ruble = (temp1 + temp2) / 60;
	add.kopeck = (temp1 + temp2) % 60;
	return add;
}
//���������� ���������� �������-�������� �����
istream& operator>> (istream& in, money& t)
{
	cout << "\n������� �����: "; in >> t.ruble;
	cout << "\n������� �������: "; in >> t.kopeck;
	return in;
}
ostream& operator<< (ostream& out, const money& t)
{
	return (out << t.ruble << " : " << t.kopeck);
}