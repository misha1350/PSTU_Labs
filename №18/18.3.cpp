#include <iostream>
#include "money.h"

using namespace std;

void main()
{
    money a;
    money b;
    money c;
    cout << "\nВведите рубли - "; cin >> a;
    cout << "\nВведите копейки - "; cin >> b;
    a++;
    cout << "a+1 копейка = " << a << endl;
    c = (a++) + b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = (a+1 копейка + b) = " << c << endl;
}