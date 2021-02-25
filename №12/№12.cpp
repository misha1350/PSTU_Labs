//WIP

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
  string passport;
  int pos;
};

void fill_out(vector<str> &citizen, int n)
{
  citizen.clear();
  ifstream name1("name.txt");
  string name2[100];
  for (int i = 0; i < 100; i++)
  {
    string data;
    name1 >> data;
    name2[i] = data;
  }
  name1.close();
  str test;
  for (int i = 0; i < n; i++)
  {
    test.name = name2[rand() % n+1];
    test.pos = i + 1;
    citizen.push_back(test);
  }
}

void print(vector<str> citizen, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << citizen[i].pos << endl;
    cout << citizen[i].name << endl << endl;
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
  
  return 0;
}

