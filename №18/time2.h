#pragma once
#include <iostream>

class Time:public triad {
public:
    Time(void);
    ~Time(void);
    Time(int, int, int);
    Time(const Time&);

    void hrs(int);
    void mins(int);
    void secs(int);
    
    void show();
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


bool Time::operator == (const Time& other) {
  return this->first == other.first && this->second == other.second && this->third == other.third;
}
bool Time::operator != (const Time& other) {
  return !(this->first == other.first || this->second == other.second || this->third == other.third);
}
bool Time::operator < (const Time& other) {
  return this->first < other.first && this->second < other.second&& this->third < other.third;
}
bool Time::operator > (const Time& other) {
  if (this->first > other.first) return true;
  if (this->first == other.first) {
    if (this->second > other.second) return true;
    else if (this->second == other.second && this->third > other.third) return true;
  }
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

void Time::show() {
  cout << "\nYear (first):\t" << first;
  cout << "\nMonth (second):\t" << second;
  cout << "\nDay (third):\t" << third << "\n";
}

/*Базовый класс:
Тройка чисел(triad)
Первое число(first) - int
Второе число(second) - int
Третье число(third) - int
1. Определить методы изменения полей и сравнения триады
2. Создать произвольный класс time с полями часы, минуты и секунды
3. Определить полный набор операций сравнения  временных промежутков*/
