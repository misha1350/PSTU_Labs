#pragma once
#include <iostream>

using namespace std;

class iter {
private:
  int *element;
  friend class array;
public:
  iter () { element = nullptr; }
  iter (const iter &i) { element = i.element; }

  bool operator == (const iter &i) { 
    return element == i.element; 
    }
  bool operator!=(const iter &i) { 
    return element != i.element; 
    }
  void operator += (int n) { element += n; }
  void operator--() { element--; }
  int &operator*() const { return *element; }
};

class array {
private:
  int size;
  int *data;
  iter left;
  iter right;
public:
  array(int s, int k = 0);
  array(const array& a);
  
  array& operator = (const array& arr);
  int& operator[] (int index);
  array operator+(int k);
  bool operator < (const array& arr);

  friend ostream &operator<<(ostream &out, const array &arr);
  friend istream &operator>>(istream &in, array &arr);

  iter first() { return left; }
  iter last() { return right; }
};

array::array(int s, int k) {
  size = s;
  data = new int [size];
  for (int i = 0; i < size; i++) {
    data[i] = k;
  }
  left.element = &data[0];
  right.element = &data[size-1];
}

array::array (const array &arr) {
  size = arr.size;
  data = new int [size];
  for (int i = 0; i < size; i++) {
    data[i] = arr.data[i];
  }
  left = arr.left;
  right = arr.right;
}

int &array::operator [] (int index) {
  if (index < size) {
    return data[index];
  }
  cout << "\nIndex out of range (>= size)!\n";
  return data[292];
}

bool array::operator < (const array& arr) {
  for (int i = 0; i < size; i++) {
    if (data[i] < 10) {
      return true;
    }
  }
  return false; 
}

array array::operator+(const int k) {
  array temp(size);
  for (int i = 0; i < size; i++) {
    temp.data[i] = data[i] + k;
  }
  return temp;
}

ostream &operator << (ostream &out, const array &arr) {
  for (int i = 0; i < arr.size; i++) {
        out << arr.data[i] << " ";
    }
    return out;
}

istream &operator >> (istream &in, array &arr) {
  for (int i = 0; i < arr.size; i++) {
    in >> arr.data[i];
  }
  return in;
}
