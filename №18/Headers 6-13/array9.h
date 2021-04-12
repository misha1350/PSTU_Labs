#pragma once
#include <iostream>
#include "error.h"

using namespace std;

// class iter {
// private:
//   int *element;
//   friend class array;
// public:
//   iter () { element = nullptr; }
//   iter (const iter &i) { element = i.element; }

//   bool operator == (const iter &i) { 
//     return element == i.element; 
//     }
//   bool operator!=(const iter &i) { 
//     return element != i.element; 
//     }
//   void operator += (int n) { element += n; }
//   void operator--() { element--; }
//   int &operator*() const { return *element; }
// };

const int max_size = 10;
class array {
private:
  int size;
  int *data;
  // iter left;
  // iter right;
public:
  array(int s);
  array(int s, int *mas);
  array(const array& arr);
  ~array();
  
  const array& operator = (const array& arr);
  int& operator[] (int index);
  array operator+(int k);
  // int operator()() const;
  bool operator < (const array& arr);

  friend ostream &operator<<(ostream &out, const array &arr);
  friend istream &operator>>(istream &in, array &arr);

  // iter first() { return left; }
  // iter last() { return right; }
};

array::array(int s) {
  if (s > max_size) throw max_size_error();
  size = s;
  data = new int [size];
  for (int i = 0; i < size; i++) {
    data[i] = 0;
  }
  // left.element = &data[0];
  // right.element = &data[size-1];
}

array::array (const array &arr) {
  size = arr.size;
  data = new int [size];
  for (int i = 0; i < size; i++) {
    data[i] = arr.data[i];
  }
  // left = arr.left;
  // right = arr.right;
}

array::~array() {
  if (data!=0) delete[]data;
}

array::array(int s, int *mas) {
  size = s;
  data = new int [size];
  for (int i = 0; i < size; i++) {
    data[i] = mas[i];
  }
}

const array& array::operator = (const array &arr) {
  if(this == &arr) return *this;
  if(data != 0) delete []data;
  size = arr.size;
  data = new int [size];
  for (int i = 0; i < size; i++) {
    data[i] = arr.data[i];
  }
  return *this;
}

int &array::operator [] (int index) {
  if (index < 0) throw index_error1();
  if (index >= size) throw index_error2();
  return data[index];
}

bool array::operator < (const array& arr) {
  for (int i = 0; i < size; i++) {
    if (data[i] < 10) {
      return true;
    }
  }
  return false; 
}

array array::operator+( int k ) {
  if (size+1 == max_size) throw max_size_error();
  array temp(size+1, data);
  temp.data[size] = k;
  return temp;
}

ostream &operator << (ostream &out, const array &arr) {
  if (arr.size == 0) out << "\narr Empty\n";
  else {
  for (int i = 0; i < arr.size; i++) {
        out << arr.data[i] << " ";
    }
    out << endl;
  }
  return out;
}

istream &operator >> (istream &in, array &arr) {
  for (int i = 0; i < arr.size; i++) {
    cout << " > ";
    in >> arr.data[i];
  }
  return in;
}
