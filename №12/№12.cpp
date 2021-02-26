// WIP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

struct str
{
  string name;
  string date_of_birth;
  string passport_region;
  int pos;
};

void fill_out(vector<str> &citizen, int n)
{
  citizen.clear();
  ifstream name1("name.txt");
  string name2[101];
  for (int i = 0; i < 101; i++)
  {
    string data;
    name1 >> data;
    name2[i] = data;
  }
  name1.close();
  str test;
  for (int i = 0; i < n; i++)
  {
    test.name = name2[rand() % (35)];
    test.pos = i + 1;
    citizen.push_back(test);
  }
}

void print(vector<str> citizen, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << citizen[i].pos << endl;
    cout << citizen[i].name << "\n\n";
  }
}

void save(vector<str> citizen, int n)
{
  string save_name;
  cout << "Введите название файла для сохранения...\t";
  cin >> save_name; 
  save_name += ".txt";
  ofstream save(save_name);
  for (int i = 0; i < n; i++)
  {
    save << citizen[i].pos << endl;
    save << citizen[i].name << "\n\n";
  }
  save.close();
  cout << "\nФайл сохранён.";
}

void search(string str2, string sub, bool flag)
{
  int str_line, sub_line;
  str_line = str2.size();
  sub_line = sub.size();
  if (sub_line != 0 && str_line != 0)
  {
    for (int i = 0; i <str_line - sub_line + 1; i++)
    {
      for (int j = 0; j < sub_line; j++)
      {
        if (sub [j] != str2[i+1])
        {
          goto retard;
        }
        else if (j == sub_line - 1)
        {
          flag = true;
          goto retard;
        }
      }
    }
  }
}

int main()
{
  setlocale(LC_ALL, "ru");
  srand(time(0));
  vector<str> citizen;
  int command, n;
  //cout << "Введите команду:\n1. Заполнение\n2. Удаление\n3. Отмена удаления\n4. Сохранение изменений\n";
  //cin >> command;
  cin >> n;
  fill_out(citizen, n);
  print(citizen, n);
  
  save(citizen, n);


  return 0;
}

