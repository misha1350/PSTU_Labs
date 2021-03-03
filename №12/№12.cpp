// WIP


// 19. ФИО, дата рождения, №паспорта. Ключ - №паспорта.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

struct str
{
  string name;
  string date_of_birth;
  string passport_region;
  string passport_no;
  int pos;
};

namespace rng //Глобальный рандомайзер, объявляется один раз на всё выполнение программы
{
  mt19937 mersenne{ static_cast<mt19937>(time(nullptr)) 
  };
}

int throw_me_some_numbers(int min, int max)
{
  uniform_int_distribution threshold {min, max};
  return threshold(rng::mersenne);
}

void fill_out(vector<str> &citizen, int n)
{
  citizen.clear();
  ifstream name1("name.txt");
  string name2[35];
  int p1, p2;
  for (int i = 0; i < 35; i++)
  {
    string data;
    name1 >> data;
    name2[i] = data;
  }
  name1.close();
  str test;
  for (int i = 0; i < n; i++)
  {
    p1 = throw_me_some_numbers(4000, 4999);
    p2 = throw_me_some_numbers(100000, 999999);
    test.name = name2[throw_me_some_numbers(1, 34)];
    test.pos = i + 1;
    test.passport_region = std::to_string(p1);
    test.passport_no = std::to_string(p2);
    citizen.push_back(test);
  }
}

void print(vector<str> citizen, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << endl << citizen[i].pos << "." << endl;
    cout << citizen[i].name << endl;
    cout << citizen[i].passport_region << endl;
    cout << citizen[i].passport_no << endl;
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
    save << endl << citizen[i].pos << "." << endl;
    save << citizen[i].name << endl ;
    save << citizen[i].passport_region << endl;
    save << citizen[i].passport_no << endl;
  }
  save.close();
  cout << "\nФайл сохранён.";
}

void line_search (vector<str> citizen, int n, string search_region, string search_no)
{
  bool flag = 0;
  for (int i = 0; i < n; i++)
  {
    if (citizen[i].passport_region == search_region && citizen[i].passport_no == search_no)
    {
      cout << "\nЭлемент находится под " << i+1 << "-ым номером множества";
      flag = true;
    }
  }
  if (flag != true)
  {
    cout << "\nЭлемент не найден.";
  }
}

void substring_search(vector<str> citizen, string str2, string sub, bool flag, int n, int int_prompt)
{
  int str_length, sub_length, count = 0;
  sub_length = sub.size();
  for (int i = 0; i < n; i++)
  {
    if (int_prompt == 1)
    {
    str2 = citizen[i].passport_region;
    }
    else 
    {
      str2 = citizen[i].passport_no;
    }
    str_length = str2.size();
    cout << "\nstr2 [" << i << "] = " << str2;
    cout << "\t\tstr_length [" << i << "] = " << str_length;
    if (str_length > 0 && sub_length > 0)
    {
      for (int l = 0; l < str_length - sub_length + 1; l++)
      {
        if (str2[l] == sub[0])
        {
          for (int j = 0; j < sub_length; j++)
          {
            if (sub [j] == str2[l+j])
            {
              count++;
            }
          }
          cout << "\t\tcount =" << count;
          if (count == sub_length) //Если счётчик подходящих символов равен длине подстроки, т.е. подстрока полностью сочетается со строкой
          {
            flag = true;
            cout << "\n\nПодстрока есть в строке. Элемент:\n" << citizen[i].pos << endl << citizen[i].name << endl << citizen[i].passport_region << endl << citizen[i].passport_no << endl;
            l = str_length; //Выходим из l-го for'а, не используя break
            i = n; //Выходим из i-го for'a
          }
        }
      }
    }
    count = 0;
  }
  if (flag != true)
  {
    cout << "\nПодстрока не найдена в строке.";
  }
}

int main()
{
  setlocale(LC_ALL, "ru");  
  vector<str> citizen;
  int command = 10, n = -1;
  bool cancel = 0;
  cout << "\nЛабораторная работа №12: Поиск данных.";
  while (command != 0)
  {
    cout << "\n\n\nВведите команду:\n1. Заполнение списка\n5. Линейный поиск\n6.Поиск подстроки в строке\n7. Сохранение изменений\n0.Стоп:\t";
    cin >> command;
    if (command == 1)
    {
      while (n < 0) // Для повторного захода в комманду нужно удалить заполненный список (вернуть значение n обратно на -1)
      {
        cout << "\n\nСколько человек? (Для отмены введите 0):\t";
        cin >> n;
        if (n > 0) // Если да
        {
          fill_out(citizen, n);
          print(citizen, n);
        }
        if (n == 0) // Если отмена
        {
          cout << "\nОтменено.\n\n\n\n";
          cancel = true;
        }
        if (n < 0)
        {
        cout << "\nОшибка. Для заполнения списка нужен хотя-бы один человек.\n\n";
        }
      }
    }
    if (command == 5)
    {
      if (n > 0) 
      {
        char prompt;
        do
        {
          prompt = 'n';
          string search_region, search_no;
          cout << "\n\n\n ***Линейный поиск по паспортным данным***\n\n\n" << "Введите номер серии паспорта (первые 4 красные цифры. Пробел ставить не нужно.):\t";
          cin >> search_region;
          cout << "\nТеперь введите номер паспорта (остальные 6 цифр):\t";
          cin >> search_no;
          line_search (citizen, n, search_region, search_no);
          cout << "\n\nПовторить линейный поиск? (y/n)\t";
          cin >> prompt;
        }
        while (!cin.fail() && prompt != 'n');
      }
      else { cout << "Для начала заполните список."; }
    }
    if (command == 6)
    {
      char prompt;
      int int_prompt;
      {
         if (n > 0) 
        {
          do
          {
            string str2, sub;
            bool flag;
            cout << "\n\n\n *****Прямой поиск строки по паспортным данным*****\n\n\n" << "Что вы хотите найти?\n1. Строку по серии паспорта\n2. Строку по номеру паспорта\n0.Отмена\t";
            cin >> int_prompt;
            if (int_prompt == 1)
            {
              cout << "\nВведите от 1 до 4 цифр искомой серии паспорта:\t";
              cin >> sub;
              substring_search(citizen, str2, sub, flag, n, int_prompt);
            }
            else if (int_prompt == 2)
            {
              cout << "\nВведите от 1 до 4 цифр искомого номера паспорта:\t";
              cin >> sub;
              substring_search(citizen, str2, sub, flag, n, int_prompt);
            }
            else if (int_prompt == 0)
            { prompt = 'n'; cancel = true;}
            else
            {
              cout << "\nНеправильный выбор.";
            }
            if (cancel != true)
            {
              cout << "\n\nПовторить линейный поиск? (y/n)\t";
              cin >> prompt;
            }
            cancel = false;
          }
        while (!cin.fail() && prompt != 'n');
        }
      }
    }
      if (command == 7)
      {
        if (n > 0) 
        {
          save(citizen, n); 
        }
        else 
        { 
          cout << "\nСохранить невозможно. Сначала надо заполнить список.\n\n";
        }
      }
      if (cancel == true)
      {
        n = -1;
      }
    }
    cout << "\n\n\n\nВыход из программы...";
    return 0;
  }
