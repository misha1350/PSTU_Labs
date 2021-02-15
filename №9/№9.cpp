/*
19.
1) Скопировать из файла F1 в файл F2 все строки, в которых нет одинаковых слов. 
2) Определить количество согласных букв в последней строке F2. 
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");
    ifstream F1("F1.txt");
    ofstream F2("F2.txt")
