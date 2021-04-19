#include <iostream>
#include <fstream>
#include <string>
#include "money10.h"

using namespace std;

int make_file (const char* f_name)
{
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

int print_file (const char *f_name)
{
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
