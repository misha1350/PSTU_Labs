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
void Line_splitting(string* wordstring, string line, int count)
{
    int j = 0;
    for (int i = 0; i < count; i++)
    {
        wordstring[i] = "";
        while (line[j] == ' ') 
        {
            j++;
        }
        while (line[j] != ' ' && line[j] != '\n' && line[j] != '\0' && line[j] != '(' && line[j] != ')' && line [j] != ',') 
        {
            wordstring[i] += line[j++];
        }
    }
}
int similarity(string* wordstring, int count, bool& flag)
{
    int num;
    for (int i = 0; i < count; i++)
    {
        if (wordstring[i+1] == wordstring[0])
        {
            flag = true;
        }
    }
    return flag;
}
int consonants(string* wordstring, int count, string cons, int& conscount)
{
  conscount = 0;
  for (int i = 0; i < count; i++)
  {
    for (int j = 0; j < wordstring[i].length(); j++)
    {
      for (int l = 0; l < 20; l++)
      {
        if (wordstring[i][j] == cons[l])
        {
          conscount++;
        }
      }
    }
  }
  return conscount;
}
int main()
{
    setlocale(LC_ALL, "ru");
    ifstream If("F1.txt");
    ofstream Of("F2.txt");
    string line;
    string cons = "bcdfghjklmnpqrstvwxz";
    int value, numMax = 0, count, num = 0, kol = 0, kol2 = 0, conscount = 0, true_conscount = 0;
    bool flag;
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
            count = Wordcount(line, value); //количество слов в строке
            string* wordstring = new string[count];
            Line_splitting(wordstring, line, count);
            numMax = similarity(wordstring, count, flag);
            conscount = consonants(wordstring, count, cons, conscount);
            if (flag != true)
            {
                Of << line << endl;
                kol++;
                true_conscount = conscount;
            }
            flag = 0; //сброс флага, если он стал true
        }
        if(If.eof())
        {
        cout << "\nКоличество согласных букв в последней строке: " << true_conscount << endl;
        }
    }
    If.close();
    Of.close();
    return 0;
}
