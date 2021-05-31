/*
Вариант  19

Тип информационного поля char. Найти высоту дерева.
*/


#include <iostream>
#include "20.h"
using namespace std;


int main()
{
    btree t;
    int n;

    cout << "N? ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        t.insert(a);
    }

    t.print();
    t.kol();
}
