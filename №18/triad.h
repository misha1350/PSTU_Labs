#pragma once
#include <iostream>

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
  void set_triad(int, int, int);
	triad& operator=(const triad&);
  bool operator==(const triad&);
	
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
triad::~triad() {}
// triad::triad(int a, int b, int c)
// {
//     first = a;
//     second = b;
//     third = c;
// }
triad::triad(int first, int second, int third)
{
this->first = first;
this->second = second;
this->third = third;
}

// triad::triad(const triad& triad) {
//     first = triad.first;
//     second = triad.second;
//     third = triad.third;
// }

triad::triad(const triad& other)
{
this->first = other.first;
this->second = other.second;
this->third = other.third;
}

triad& triad::operator = (const triad& other) {
  this->first = other.first;
  this->second = other.second;
  this->third = other.third;
  return *this;
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

// triad& triad::operator=(const triad& t) {
//     if (&t == this) return *this;
//     first = t.first;
//     second = t.second;
//     third = t.third;
//     return *this;
// }

bool triad::operator==(const triad& other)
{
return this->first == other.first && this->second == other.second && this->third == other.third;
}


void triad::set_triad(int first, int second, int third)
{
this->first = first;
this->second = second;
this->third = third;
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
