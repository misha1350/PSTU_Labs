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
  

	bool operator == (const money&);
	money& operator=(const money&);
	money& operator++();
	money operator++(int); 
	money operator+(const money&);
  money operator+=(const money&);
  // money operator/(const money&);
  money operator /(const int value);
  bool operator<(const money&) const;
  bool operator>(const money&) const;

	friend istream& operator>> (istream& in, money& t);
	friend ostream& operator<< (ostream& out, const money& t);
};

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

// bool money:: operator == (const money& other)
// {
//     return this->ruble == other.ruble && this->kopeck == other.kopeck;
// }

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

// money money::operator / (const money& t)
// {
//   long temp3 = ruble * 100 + kopeck;
//   money div;
//   div.ruble = temp3 / 200;
//   div.kopeck = temp3 % 100;
//   div.kopeck = temp3 / 2;
// 	return div;
// }

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
