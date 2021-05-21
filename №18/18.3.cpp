#include <iostream>
#include "Headers/money.h"

using namespace std;

int main()
{
  cout << "**18.3** Сложение двух сумм:\n";
    money a;
    money b;
    money c;
    cin >> a;
    cin >> b;
    a++;
    cout << "\nК сумме А прибавлена копейка: " << a << "\n";
    cout << "А = " << a << endl;
    cout << "B = " << b << endl;
    c = (a++) + b;
    cout << "C = (A + B) = " << c << endl;
}
