#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
19.
1) Скопировать из файла F1 в F2 все строки, в которых нет слов, совпадающих с первым словом
2) Определить количество согласных букв в последней строке F2.
*/

int Wordcount(string line, int value)
{
    int count = 0;
    for (int i = 1; i < value; i++)
    {
        if (line[i] == ' ' && line[i - 1] != ' ') //если символ в конце условного слова в строке - пробел и предыдущий символ - не пробел
        {
            count++;
        }
    }
    if (line[value - 1] != ' ') //если предпоследний символ в строке не пробел, т.е. в строке только одно слово
    {
        count++;
    }
    return count;
}
void Line_splitting(string* NewSTR, string line, int count)
{
    int j = 0;
    for (int i = 0; i < count; i++)
    {
        NewSTR[i] = "";
        while (line[j] == ' ') 
        {
            j++;
        }
        while (line[j] != ' ' && line[j] != '\n' && line[j] != '\0')
        {
            NewSTR[i] += line[j++];
        }
    }
}
int foo(string* NewSTR, int count/*, string cons, int& max*/)
{
    int num;
    for (int i = 0; i < count; i++)
    {
        if (NewSTR[i+1] == NewSTR[0])
        {
            cout << NewSTR[i] << endl;
            num = i + 1;
        }
    }
    return num;
}
//    int  num, g;
//    for (int i = 0; i < count; i++)                             //итерация по строке (слова в строке)
//    {
//        g = 0;
//        for (int j = 0; j < NewSTR[i].length(); j++)        //итерация по слову (буквы в слове)
//        {
//            for (int l = 0; l < 20; l++)                    //сравнение каждой буквы с гласными
//            {
//                if (NewSTR[i][j] == cons[l])
//                {
//                    g++;
//                }
//            }
//        }
//        if (max < g)
//        {
//            max = g;
//            num = i + 1;
//        }
//    }
//    return num;
//}
int main()
{
    setlocale(LC_ALL, "ru");
    ifstream If("F1.txt");
    ofstream Of("F2.txt");
    string line;
    string cons = "bcdfghjklmnpqrstvwxz";
    int value, numMax = 0, count, num = 0, kol = 0, g, gp = 0;
    if (!If.is_open())
    {
        cout << "Ошибка открытия файла F1.txt!";
    }
    else
    {
        while (!If.eof())
        {
            getline(If, line);
            value = line.length();  
            count = Wordcount(line, value);               //количество слов в строке
            string* NewSTR = new string[count];
            Line_splitting(NewSTR, line, count);
            cout << NewSTR[0] << endl;
            numMax = foo(NewSTR, count/*, cons, g*/);
            /*if (gp < g)
            {
                num = numMax + kol;
                gp = g;
            }
            if (count > 2)
            {
                Of << line << endl;
            }
            kol += count;
            g = 0;*/
        }
        cout << "Номер слова, в котором больше всего гласных букв: " << num << endl;
    }

    If.close();
    Of.close();
    return 0;
}
