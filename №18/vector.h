#pragma once
#include "object.h"
#include <iostream>

using namespace std;

class vector {
public:
    vector(void);
    vector(int);
public:
    ~vector(void);
    void add(object *);
    friend ostream &operator<<(ostream &out, const vector &v);
private:
    object **start;
    int size;
    int pos;
};


vector::vector() {
  start = 0;
  size = 0;
  pos = 0;
}

vector::vector (int n) {
  start = new object* [n];
  size = n;
  pos = 0;
}

vector::~vector() {
  if (start != 0) delete [] start;
  start = 0;
}

void vector::add(object *p) {
  if (pos < size) {
    start[pos] = p;
    pos++;
  }
}

ostream& operator << (ostream& out, const vector &vec) {
  if (vec.size == 0) out << "vector is empty\n";
  object **p = vec.start;
  for (int i = 0; i< vec.pos; i++) {
    (*p)->show();
    p++;
  }
  return out;
}
