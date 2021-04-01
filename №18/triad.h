#pragma once
#include <iostream>

/*Базовый класс:
Тройка чисел(triad)
Первое число(first) - int
Второе число(second) - int
Третье число(third) - int
1. Определить методы изменения полей и сравнения триады
2. Создать произвольный класс time с полями часы, минуты и секунды
3. Определить полный набор операций сравнения авременных промежутков*/

class triad
{
public:
	triad(void);
	virtual ~triad(void);
	triad(int, int, int);
	triad(const triad&);

	int get_first() { return first; }
	int get_second() { return second; }
	int get_third() { return third; }

	void set_first(int);
	void set_second(int);
	void set_third(int);

	triad& operator=(const triad&);
	
	friend istream& operator>>(istream& in, triad& t);
	friend ostream& operator<<(ostream& out, const triad& t);

    int first;
    int second;
    int third;
};

triad::triad()
{
    first = 0;
    second = 0;
    third = 0;
}
triad::~triad()
{
}
triad::triad(int a, int b, int c)
{
    first = a;
    second = b;
    third = c;
}

triad::triad(const triad& triad) {
    first = triad.first;
    second = triad.second;
    third = triad.third;
}

void triad::set_first(int e) {
    first = e;
}

void triad::set_second(int e) {
    second = e;
}

void triad::set_third(int e) {
    third = e;
}

triad& triad::operator=(const triad& t) {
    if (&t == this) return *this;
    first = t.first;
    second = t.second;
    third = t.third;
    return *this;
}

istream& operator>>(std::istream& in, triad& t) {
    cout << "\nfirst: "; in >> t.first;
    cout << "\nsecond: "; in >> t.second;
    cout << "\nthird: "; in >> t.third;
    return in;
}
ostream& operator<<(ostream& out, const triad& t) {
    out << "\nfirst: " << t.first;
    out << "\nsecond: " << t.second;
    out << "\nthird: " << t.third;
    out << endl;
    return out;
}
