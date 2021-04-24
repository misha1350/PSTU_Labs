#include <iostream>
#include <fstream>
#include <string>
#include "money10.h"

using namespace std;

int make_file (const char* f_name) {
  fstream stream (f_name, ios::out|ios::trunc);
  if(!stream)return -1;
  int n;
  money t;
  cout << "\n\tN? "; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    stream << t;
  }
  stream.close();
  return n;
}

int print_file (const char *f_name) {
  fstream stream(f_name, ios::in);
  if (!stream) return -1;
  money t; int i = 0;
  while (stream >> t) {
    cout << t;
    i++;
  }
  stream.close();
  return i;
}

int add_entry(const char *f_name, int num, money t1) {
  fstream temp("temp", ios::out);
  fstream stream(f_name, ios::in);
  if (!stream) return -1;
  money t; int i = 0, l = 0;
  while (stream >> t) {
    if (stream.eof()) break;
    i++;
    if(i == num) {
      temp << t1;
      l++;
    }
    temp << t;
  }
  stream.close(); temp.close();
  remove(f_name);
  rename("temp", f_name);
  return l;
}

int add_end(const char *f_name, money t1) {
  fstream stream(f_name, ios::app);
  if(!stream) return -1;
  stream << t1;
  return 1;
}

int del_entry (const char *f_name, int num) {
  fstream temp("temp", ios::out);
  fstream stream (f_name, ios::in);
  if (!stream) return -1;
  money t; int i = 0;
  while (stream >> t) {
    if (stream.eof()) break;
    i++;
    if (i!=num) temp << t;
  }
  stream.close(); temp.close();
  remove(f_name);
  rename("temp", f_name);
  return i;
}

int change_entry(const char *f_name, int num, money t2) {
  fstream temp("temp", ios::out);
  fstream stream(f_name, ios::in);
  if (!stream) return -1;
  money t; int i = 0, l = 0;
  while (stream >> t) {
    if (stream.eof()) break;
    i++;
    if (i == num) {
      cout << endl << t << " is being replaced\n";
      temp << t2;
      l++;
    }
    else temp << t;
  }
  stream.close(); temp.close();
  remove(f_name);
  rename("temp", f_name);
  return l;
}
