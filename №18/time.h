#pragma once
#include <iostream>
#include "triad.h"

class Time:public triad {
public:
    Time(void);
    ~Time(void);
    Time(int, int, int);
    Time(const Time&);

    void hrs(int);
    void mins(int);
    void secs(int);

    /// Перегруженные операции
    Time& operator++();
    Time operator++(int); // Постфиксная операция
    Time operator+(int);
};

Time::Time(void):triad() {}
Time::~Time(void) {}
Time::Time(int Hrs, int Mins, int Secs):triad(Hrs, Mins, Secs) {}
Time::Time(const Time &D) {
    first = D.first;
    second = D.second;
    third = D.third;
}


Time& Time::operator++() { 
	int temp = first * 24 + second * 60 + third * 60;
	temp += 1;
	first = temp / 24;
	temp = temp % 24;
	second = temp / 60;
	temp = temp % 60;
	third = temp / 60;
	return *this;
}

Time Time::operator++(int) {
    int temp = first * 24 + second * 60 + third * 60;
	  temp += 1;

    Time t(first, second, third);

    first = temp / 24;
	  temp = temp % 24;
	  second = temp / 60;
	  temp = temp % 60;
	  third = temp / 60;
    return t;
}

Time Time::operator+(int days) {
    int temp = first * 24 + second * 60 + third * 60;

    Time t(first, second, third);
    first = temp / 24;
	  temp = temp % 24;
	  second = temp / 60;
  	temp = temp % 60;
	  third = temp / 60;
    return t;
}

void Time::hrs(int Hrs) {
    first = Hrs;
}

void Time::mins(int Mins) {
    second = Mins;
}

void Time::secs(int Secs) {
    third = Secs;
}
