#pragma once
#include <iostream>
#include "object.h"

using namespace std;

class triad: public object
{
public:
	triad(void);
	virtual ~triad(void);
  void show();
	triad(int, int, int);
	triad(const triad&);

	int get_first() { return first; }
	int get_second() { return second; }
	int get_third() { return third; }

	void set_first(int);
	void set_second(int);
	void set_third(int);
  void set_triad(int, int, int);
	triad& operator=(const triad&);
	
	friend istream& operator>>(istream& in, triad& t);
	friend ostream& operator<<(ostream& out, const triad& t);

protected:
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
triad::~triad() {}

triad::triad(int first, int second, int third)
{
this->first = first;
this->second = second;
this->third = third;
}

triad::triad(const triad& other)
{
this->first = other.first;
this->second = other.second;
this->third = other.third;
}



void triad::set_first(int d) {
    first = d;
}

void triad::set_second(int e) {
    second = e;
}

void triad::set_third(int f) {
    third = f;
}

triad& triad::operator = (const triad& other) {
  this->first = other.first;
  this->second = other.second;
  this->third = other.third;
  return *this;
}

void triad::set_triad(int first, int second, int third)
{
this->first = first;
this->second = second;
this->third = third;
}

istream& operator>>(std::istream& in, triad& t) {
    cout << "\nYear (first):\t"; in >> t.first;
    cout << "\nMonth (second):\t"; in >> t.second;
    cout << "\nDay (third):\t"; in >> t.third;
    return in;
}
ostream& operator<<(ostream& out, const triad& t) {
    out << "\nYear (first):\t" << t.first;
    out << "\nMonth (second):\t" << t.second;
    out << "\nDay (third):\t" << t.third;
    out << endl;
    return out;
}

void triad::show() {
    cout << "\nfirst:\t" << first;
    cout << "\nsecond:\t" << second;
    cout << "\nthird:\t" << third << endl;
}
