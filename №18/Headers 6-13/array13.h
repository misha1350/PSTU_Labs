#pragma once
#include <iostream>

using namespace std;

template <class T> class Array;
template <class T> ostream& operator<<(ostream &out, const Array<T> &arr);
template <class T> 
istream& operator>>(istream &in, Array<T> &arr);

template <class T>
class Array {
private:
  int size;
  T *data;
public:
  Array(int s, T k);
  Array(const Array<T> &arr);
  ~Array();
  
  // Array<T> &operator + (const Array<T> &arr);
  Array<T> &operator = (const Array<T> &arr);
  T &operator[] (int index);
  Array<T> operator+(T k);
  int operator()() const;
  bool operator < (const Array& arr);

  friend ostream &operator<< <>(ostream &out, const Array<T> &arr);
  friend istream &operator>> <>(istream &in, Array<T> &arr);

};
 
template<class T> 
Array<T>::Array(int s, T k) {
  size = s;
  data = new T[size];
  for (int i = 0; i < size; i++) {
    data[i] = k;
  }
}



template<class T>
Array<T>::Array (const Array<T> &arr) {
  size = arr.size;
  data = new T[size];
  for (int i = 0; i < size; i++) {
    data[i] = arr.data[i];
  }
}

// template <class T>
// Array<T> &Array<T>::operator + (const Array<T> &arr) {
//   if (this == &arr) return *this;
//   double addition;
//   size = arr.size;
//   size++;
//   if (data!=0) delete[] data;
//   data = new T[size];
//   for (int i = 0; i < size-1; i++) {
//     data[i]=arr.data[i];
//   }
//   data[size-1] = addition;
//   // return *this;
// }

template <class T>
Array<T> &Array<T>::operator = (const Array<T> &arr) {
  if (this == &arr) return *this;
  size = arr.size;
  if (data!=0) delete[] data;
  data = new T[size];
  for (int i = 0; i < size; i++) {
    data[i]=arr.data[i];
  }
  return *this;
}

template<class T>
T &Array<T>::operator [] (int index) {
  if (index < size) {
    return data[index];
  }
  cout << "\nIndex out of range (>= size)!\n";
  cout << "The size of the array is: (" << size << ") and the last element in the array is: ";
  return data[size-1];
}

template<class T>
bool Array<T>::operator < (const Array<T> &arr) {
  for (int i = 0; i < size; i++) {
    if (data[i] < 10) {
      return true;
    }
  }
  return false; 
}

template<class T>
Array<T>::~Array() {
  delete[] data;
  data = nullptr;
}
// template<class T>
// Array<T> Array<T>::operator+(const int k) {
//   Array<T> temp(size);
//   for (int i = 0; i < size; i++) {
//     temp.data[i] = data[i] + k;
//   }
//   return temp;
// }

template<class T>
ostream& operator<<(ostream &out, const Array<T> &arr) {
  for (int i = 0; i < arr.size; i++) {
        out << arr.data[i] << " ";
    }
    return out;
}

template<class T> 
istream& operator>>(istream &in, Array<T> &arr) {
  for (int i = 0; i < arr.size; i++) {
    in >> arr.data[i];
  }
  return in;
} 
