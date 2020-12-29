#include <iostream>
#include<ctime>
#include<string>
using namespace std;

//Написать перегруженные функции и основную программу,
//которая их вызывает.
//
//22
//а) для массива целых чисел находит минимальный элемент
//
//б) для строки находит длину самого короткого слова

float Foo(float* a, int size)                
{
    float max = a[0];
    for (int i = 0; i < size; i++)
    {
        if (a[i] <= max )
        {
            max = a[i];
        }
    }
    return max;
}

int Foo(string str, int coun)               //перегрузка для строки
{
    int k = 0;
    int min = 999;
    for (int i = 0; i < coun; i++)
    {
        if (str[i] != *" ")
        {
            k++;                            //счётчик букв в слове
            if (str[i] == *"." || str[i] == *"," || str[i] == *"!" || str[i] == *"?") //исключаем знаки припенания
            {
                k--;
            }
        }
        if (str[i] == *" " && str[i-1] != *" ")
        {
            if (k<min)
            {
                min = k;
            }
            k = 0;
        }
    }
    return min;
}

int main()
{

    string str;
    cout << "Введите предложение" << "\n";
    getline(cin, str);                        
    int coun = str.length();                  
    int Count = Foo(str, coun);               

    int size = -1;
    string type = "слово";
    while (size <= 0)                         // защита от дурака (размер массива > 0)
    {
        cout << "Введите размер массива чисел" << "\n";
        cin >> size;
        if (size <= 0)
        {
            cout << "Ошибка!" << "\n";
        }
    }
    float* a = new float[size];                   //Сделал int, т.к. хз как на вещественные сделать указатель
    while (type != "случайно" && type != "вручную")
    {
        cout << "Введите способ заполнения массива(случайно, вручную)" << "\n";
        cin >> type;
        if (type != "случайно" && type != "вручную")        // защита от дурака
        {
            cout << "Ошибка!" << "\n";
        }
    }
    cout << "\n";
    if (type == "случайно")
    {
        cout << "Массив:" << "\n";
        for (int i = 0; i < size; i++)
        {
            a[i] = rand() % 100-50;              
        }
        for (int i = 0; i < size; i++)         //Вывод 
        {
            cout << a[i] << "  ";
        }
    }
    else
    {
        cout << "Введите массив:" << "\n";
        for (int i = 0; i < size; i++)
        {
            cin >> a[i];
        }
    }
    cout << "\n" << "\n";
    cout << "Минимальный элемент в массиве:  ";
    float M = Foo(a, size);  
    cout << M << "\n";
    cout << "\n" << "\n" << "Длина самого короткого слова в строке:  ";
    cout << Count << "\n";
}
