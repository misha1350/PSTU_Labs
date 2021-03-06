#pragma once
#include <iostream>
using namespace std;

/*
Вариант 9 (19)
Два поля - long для рублей и int для копеек. Дробная часть отделяется запятой. Реализовать:
*/

class money {
	long ruble; int kopeck;
public:
	money();
	money(long a, int b) ;
	money(const money& t) ;
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
  
	money& operator=(const money&);
	money& operator++();
	money operator++(int);
	money operator+(const money&);

	friend istream& operator>> (istream& in, money &t);
	friend ostream& operator<< (ostream& out, const money &t);

};

money::money() {
	ruble = 0; kopeck = 0;
}

money::money(long a, int b) {
	ruble = a; kopeck = b;
}

money::money(const money &t) {
  ruble = t.ruble; kopeck = t.kopeck;
}

money& money::operator=(const money& t)
{

	if (&t == this) {
		return *this;
  }
	ruble = t.ruble;
	kopeck = t.kopeck;
	return *this;
}

money& money::operator++()
{
	long temp = ruble * 100 + kopeck;
	temp++;
	ruble = temp / 100;
	kopeck = temp % 100;
	return *this;
}

money money::operator++ (int)
{
	long temp = ruble * 100 + kopeck;
	temp++;
	money t(ruble, kopeck);
	ruble = temp / 100;
	kopeck = temp % 100;
	return t;
}

money money::operator+ (const money& t)
{
	long temp1 = ruble * 100 + kopeck;
	long temp2 = t.ruble * 100 + t.kopeck;
	money add;
	add.ruble = (temp1 + temp2) / 60;
	add.kopeck = (temp1 + temp2) % 60;
	return add;
}

istream& operator>> (istream& in, money &t)
{
	cout << "\nВведите рубли: "; in >> t.ruble;
	cout << "\nВведите копейки: "; in >> t.kopeck;
	return in;
}
ostream& operator<< (ostream& out, const money &t)
{
	return (out << t.ruble << "." << t.kopeck);
}
