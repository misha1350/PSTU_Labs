#include <iostream>
#include "money.h"

using namespace std;

void main()
{
    money a;
    money b;
    money c;
    cout << "\n������� ����� - "; cin >> a;
    cout << "\n������� ������� - "; cin >> b;
    a++;
    cout << "a+1 ������� = " << a << endl;
    c = (a++) + b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = (a+1 ������� + b) = " << c << endl;
}