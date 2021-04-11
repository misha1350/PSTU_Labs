#pragma once
#include <iostream>

using namespace std;

template <class T>
class array {
private:
  int size;
  T *data;
public:
  array(int s, T k);
  array(const array<T> &arr);
  ~array();
  
  array<T> &operator = (const array<T> &arr);
  T &operator[] (int index);
  array<T> operator+(T k);
  int operator()() const;
  bool operator < (const array& arr);

  friend ostream &operator<< <>(ostream &out, const array<T> &arr);
  friend istream &operator>> <>(istream &in, array<T> &arr);

};
 
template<class T> 
array<T>::array(int s, T k) {
  size = s;
  data = new int [size];
  for (int i = 0; i < size; i++) {
    data[i] = k;
  }
}

template<class T>
array<T>::array (const array<T> &arr) {
  size = arr.size;
  data = new T [size];
  for (int i = 0; i < size; i++) {
    data[i] = arr.data[i];
  }
}

template<class T>
T &array<T>::operator [] (int index) {
  if (index < size) {
    return data[index];
  }
  cout << "\nIndex out of range (>= size)!\n";
  return data[292];
}

template<class T>
bool array<T>::operator < (const array<T> &arr) {
  for (int i = 0; i < size; i++) {
    if (data[i] < 10) {
      return true;
    }
  }
  return false; 
}

template<class T>
array<T>::~array() {
  delete[] data;
  data = nullptr;
}
// template<class T>
// array<T> array<T>::operator+(const int k) {
//   array<T> temp(size);
//   for (int i = 0; i < size; i++) {
//     temp.data[i] = data[i] + k;
//   }
//   return temp;
// }

template<class T>
ostream &operator<<(ostream &out, const array<T> &arr) {
  for (int i = 0; i < arr.size; i++) {
        out << arr.data[i] << " ";
    }
    return out;
}

template<class T>
istream &operator>>(istream &in, array<T> &arr) {
  for (int i = 0; i < arr.size; i++) {
    in >> arr.data[i];
  }
  return in;
}
