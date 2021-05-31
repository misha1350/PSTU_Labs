#include <iostream>
#include "19Str.h"
#include <string>
using namespace std;
int main()
{
    setlocale (LC_ALL, "ru");
    string dat;
    Str str;
    Str str2;
    int size = -1, No = -1;
    cout << "Введите количество элементов стека:\t" << endl;
    while (size <= 0)
    {
        cin >> size;
        if (size <= 0)
        {
            cout << "Введено некоректное значение!" << endl;
        }
    }
    string a;
    for (int i = 0; i < size; i++)
    {
        cout << "Введите " << i + 1 << " элемент:\t";
        cin >> a;
        str.push(a);
    }
    str.Print();
    cout << "Введите номер добавляемого элемента:\t";
    while (No <= 0 || No >= size + 2)
    {
        cin >> No;
        if (No <= 0 || No >= size + 2)
        {
            cout << "Введено некоректное значение\t" << endl;
        }
    }
    for (int i = 0; i < size - No + 1; i++)
    {
        str2.push(str.Top());
        str.pop();
    }
    cout << "Введите новый элемент:\t";
    cin >> dat;
    str.push(dat);
    for (int i = 0; i < size - No + 1; i++)
    {
        str.push(str2.Top());
        str2.pop();
    }
    str.Print();
    return 0;
}
