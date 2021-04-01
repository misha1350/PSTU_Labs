#include <iostream>

using namespace std;

#include "triad.h"
#include "time.h"

int main() {
  Time a(2020, 10, 25);
  cout << a;

  Time b(2021, 3, 21);
  cout << b;

  bool comparison = a == b;
  if (comparison == true) cout << "\nA == B";
  else cout << "\nA != B";

  bool greater_than = a > b;
  if (greater_than == true) cout << "\nA > B";
  else cout << "\nA < B";
}
