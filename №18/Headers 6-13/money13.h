#pragma once
#include <iostream>
#include <time.h>
#include <math.h>
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
	// money() {
	// 	ruble = 0; kopeck = 0;
	// };
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
  
  	money();
	bool operator == (const money&);
 	 bool operator != (const money&);
	money& operator=(const money&);
	money& operator++();
	money operator++(int); 
	money operator+(const money&);
  	// money operator +(const money& other);
	money operator +(const money& other) const;
  money operator+=(const money&);
  money operator /(const int value);
  bool operator<(const money&) const;
  bool operator>(const money&) const;

	friend istream& operator>> (istream& in, money& t);
	friend ostream& operator<< (ostream& out, const money& t);
};


int random1(long c, int d)
{
    if (c > 0) return c + rand() % (d - c);
    else return c + rand() % (abs(c) + d);
}
money::money() {
  ruble = random1 (1, 100);
  kopeck = random1 (0, 99);
}
bool money::operator < (const money& t) const
{
    if (this->ruble < t.ruble)
        return true;
    else
        return false;
}

bool money::operator > (const money& t) const
{
    if (this->ruble > t.ruble)
        return true;
    else
        return false;
}

bool money:: operator == (const money& t)
{
    return this->ruble == t.ruble && this->kopeck == t.kopeck;
}

bool money:: operator != (const money& t)
{
    return !(this->ruble == t.ruble && this->kopeck == t.kopeck);
}

money& money::operator=(const money& t)
{

	if (&t == this)
		return *this;
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
	add.ruble = (temp1 + temp2) / 100;
	add.kopeck = (temp1 + temp2) % 100;
	return add;
}
money money:: operator +(const money& t) const
{
    money tmp;
    int temp_kop = 0, temp_rub = 0;
    tmp.kopeck = this->kopeck + t.kopeck;
    if (tmp.kopeck >= 100)
    {
        temp_rub = tmp.kopeck / 100;
        temp_kop = tmp.kopeck - temp_rub * 100;
        tmp.kopeck = temp_kop;
    }
    tmp.ruble = this->ruble + t.ruble + temp_rub;
    return tmp;
}

money money::operator+= (const money &t) {
  this->ruble += t.ruble;
  this->kopeck += t.kopeck;
  return *this;
}

money money :: operator /(const int value)
{
    money tmp;
    tmp.ruble = this->ruble / value;
    tmp.kopeck = this->kopeck;
    return tmp;
}

istream& operator>> (istream& in, money& t)
{
	cout << "\nВведите рубли - "; in >> t.ruble;
	cout << "Введите копейки - "; in >> t.kopeck;
	return in;
}
ostream& operator<< (ostream& out, const money& t)
{
	return (out << t.ruble << "." << t.kopeck);
}
