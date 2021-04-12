//Вариант реализации 3

#pragma once
#include <iostream>
#include <string>

using namespace std;

class error {
public:
  virtual void what() {};
};

class index_error: public error {
protected:
  string msg;
public:
  index_error() { msg = "\nIndex error!\n"; }
  virtual void what() { cout << msg; }
};

class size_error: public error {
protected:
  string msg;
public: 
  size_error() { msg = "\nSize error!\n"; }
  virtual void what() { cout << msg; }
};

class max_size_error: public size_error {
protected:
  string msg1;
public: 
  max_size_error () { size_error(); msg1= "size > max_size\n"; }
  virtual void what() { cout << msg << msg1;}
};

class no_size: public size_error {
protected:
  string msg1;
public:
  no_size() { size_error(); msg1 = "Array is empty\n"; }
  virtual void what() { cout << msg << msg1; }
};

class index_error1: public index_error {
protected:
  string msg1;
public:
  index_error1() { index_error(); msg1 = "index < 0\n"; }
  virtual void what() { cout << msg << msg1; } 
};

class index_error2: public index_error {
protected:
  string msg1;
public:
  index_error2() {index_error(); msg1 = "index > size\n"; }
  virtual void what() { cout << msg << msg1; }
};
