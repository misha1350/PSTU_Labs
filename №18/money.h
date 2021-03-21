#pragma once
#include <iostream>
using namespace std;

/*
Вариант 9 (19)
Два поля - long для рублей и int для копеек. Дробная часть отделяется запятой. Реализовать:
- вычитание дробного числа из суммы
- операции сравнения (==, !=)
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
	//Перегруженные операции
	money& operator=(const money&);
	money& operator++();
	money operator++(int); //Постфиксная операция, параметр которой должен быть int
	money operator+(const money&);
	//Глобальные функции ввода-вывода
	friend istream& operator>> (istream& in, money& t);
	friend ostream& operator<< (ostream& out, const money& t);
};