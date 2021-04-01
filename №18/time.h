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

    Time& operator++();
    Time operator++(int); 
    Time operator+(int);
    bool operator==(const Time& other);
    bool operator!=(const Time& other);
    bool operator<(const Time& other);
    bool operator>(const Time& other);
};

Time::Time(void):triad() {}
Time::~Time(void) {}
Time::Time(int Hrs, int Mins, int Secs):triad(Hrs, Mins, Secs) {}
Time::Time(const Time &other) {
    this->first = other.first;
    this->second = other.second;
    this->third = other.third;
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

bool Time::operator==(const Time& other) {
  return this->first == other.first && this->second == other.second && this->third == other.third;
}
bool Time:: operator != (const Time& other) {
  return !(this->first == other.first && this->second == other.second && this->third == other.third);
}
bool Time:: operator < (const Time& other) {
  return this->first < other.first&& this->second < other.second&& this->third < other.third;
}
bool Time:: operator > (const Time& other) {
  return this->first > other.first && this->second > other.second && this->third > other.third;
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

/*Базовый класс:
Тройка чисел(triad)
Первое число(first) - int
Второе число(second) - int
Третье число(third) - int
1. Определить методы изменения полей и сравнения триады
2. Создать произвольный класс time с полями часы, минуты и секунды
3. Определить полный набор операций сравнения  временных промежутков*/
