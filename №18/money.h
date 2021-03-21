#pragma once
#include <iostream>
using namespace std;

/*
������� 9 (19)
��� ���� - long ��� ������ � int ��� ������. ������� ����� ���������� �������. �����������:
- ��������� �������� ����� �� �����
- �������� ��������� (==, !=)
*/

class money {
	long ruble; int kopeck;
public:
	money() {
		ruble = 0; kopeck = 0;
	};
	money(long a, int b) {
		ruble = a; kopeck = b;
	}
	money(const money& t) {
		ruble = t.ruble; kopeck = t.kopeck;
	}
	~money() {};
	int get_ruble() {
		return ruble;
	}
	int get_kopeck() {
		return kopeck;
	}
	void set_ruble(long a) {
		ruble = a;
	}
	void set_kopeck(int b) {
		kopeck = b;
	}
	//������������� ��������
	money& operator=(const money&);
	money& operator++();
	money operator++(int); //����������� ��������, �������� ������� ������ ���� int
	money operator+(const money&);
	//���������� ������� �����-������
	friend istream& operator>> (istream& in, money& t);
	friend ostream& operator<< (ostream& out, const money& t);
};