#pragma once
#include <iostream>

using namespace std;

const int max_size = 10;
class array {
private:
  int size;
  int *data;
public:
  array(int s);
  array(int s, int *mas);
  array(const array& arr);
  ~array();
  
  const array& operator = (const array& arr);
  int& operator[] (int index);
  array operator+(int k);
  bool operator < (const array& arr);

  friend ostream &operator<<(ostream &out, const array &arr);
  friend istream &operator>>(istream &in, array &arr);
};

array::array(int s) {
  if (s > max_size) throw 1;
  size = s;
  data = new int [size];
  for (int i = 0; i < size; i++) {
    data[i] = 0;
  }
}

array::array (const array &arr) {
  size = arr.size;
  data = new int [size];
  for (int i = 0; i < size; i++) {
    data[i] = arr.data[i];
  }
}

array::~array() {
  if (data!=0) delete[]data;
}

array::array(int s, int *mas) {
  if (s > max_size) throw 1; //max_size_error()
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
  if (index < 0) throw 2; //index_error1()
  if (index >= size) throw 3; //index_error2()
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
  if (size+1 == max_size) throw 4;// max_size_error();
  array temp(size+1, data);
  temp.data[size] = k;
  return temp;
}

ostream &operator << (ostream &out, const array &arr) {
  if (arr.size == 0) throw 5; //out << "\narr Empty\n";
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
