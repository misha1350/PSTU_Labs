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
  ifstream surname1("surname.txt");
  ifstream last_name("last_name.txt");
  string name2[35];
  string surname2[73];
  string last_name2[34];
  int p1, p2;
  for (int i = 0; i < 35; i++)
  {
    string data;
    name1 >> data;
    name2[i] = data;
  }
  for (int i = 0; i < 73; i++)
  {
    string data;
    surname1 >> data;
    surname2[i] = data;
  }
  for (int i = 0; i < 34; i++)
  {
    string data;
    last_name >> data;
    last_name2[i] = data;
  }
  name1.close();
  surname1.close();
  last_name.close();
  str temp;
  for (int i = 0; i < n; i++)
  {
    p1 = throw_me_some_numbers(4000, 4999);
    p2 = throw_me_some_numbers(100000, 999999);
    temp.name = name2[throw_me_some_numbers(0, 34)];
    temp.name = temp.name + ' ' + surname2[throw_me_some_numbers(0, 72)];
    temp.name = temp.name + ' ' + last_name2[throw_me_some_numbers(0, 33)];
    temp.pos = i + 1;
    temp.passport_region = std::to_string(p1); //std'шный быстрее stringstream'овского, хорошая практика
    temp.passport_no = std::to_string(p2);
    citizen.push_back(temp);
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

void KMP (vector<str> citizen, string str2, string sub, bool success, int n, int int_prompt)
// str2 - строка, sub - подстрока, которая вводится пользователем
{
  for (int i = 0; i < n; i++)
  {
    if (int_prompt == 1) {
      str2 = citizen[i].passport_region;
    }
    else {
      str2 = citizen[i].passport_no;
    }
    vector<int> pi(sub.size());
    for (int j = 0, i = 1; j < sub.size(); i++) 
    {
      while ((j > 0) && (sub[i] != sub[j])) {
        j = pi[j - 1];
      }
      if (sub[i] == sub [j]) { 
        j++; 
      }
      pi[i] = j;
    }
    for (int k = 0, l = 0; k < str2.size(); k++)
    {
      if (str2[k] == sub[l]) {
        l++; 
      }
      else {
        if (l != 0) {
          l = pi[l - 1];
        }
      }
      if (l == sub.size()) {
        success = true;
      }
    if (success == true) {
      cout << "\n\nПодстрока есть в строке. Элемент:\n" << citizen[i].pos << endl << citizen[i].name << endl << citizen[i].passport_region << endl << citizen[i].passport_no << endl;
      i = n; //Выходим из i-го for'a
    }
  }
  if (success != true) {
      cout << "\nПодстрока не найдена в строке.";
    }
  }
}

bool BM (string str2, string sub, bool success, int n, int int_prompt, int i, vector<str> citizen)
{
  int subsize = sub.size();
  int arr[256];
  int str2size, pos, j;
  
    if (int_prompt == 1) {
      str2 = citizen[i].passport_region;
    }
    else {
      str2 = citizen[i].passport_no;
    }
    str2size = str2.size();
  for (j = 0; j < 256; j++) {
      arr[j] = str2size;
    }
  for (j = subsize - 1; j >= 0; j--) {
    if ((arr[(short)(sub[j])]) == subsize) {
      (arr[(short)(sub[j])]) = subsize - j - 1;
    }
  }
  pos = subsize - 1;
  while (pos < str2size) {
    if (sub[subsize - 1] != str2[pos]) {
      pos += arr[(short)(str2[pos])];
    }
    else 
      for (j = subsize - 1; j >= 0; j--) {
      if (sub[j] != str2[pos - subsize + j + 1]) {
        pos += arr[(short)(str2[pos])];
        break;
      }
      else if (j == 0) {
        pos = str2size;
        success = true;
      }
    }
  }
return success;
}

int main()
{
  setlocale(LC_ALL, "ru");  
  vector<str> citizen;
  int command = 10, n = -1;
  bool cancel = 0, to_be_deleted = 0;
  cout << "\nЛабораторная работа №14: Поиск данных 2: Electric boogaloo";
  while (command != 0)
  {
    cout << "\n\n\nВведите команду:\n1. Заполнение списка\n2. Удаление списка\n3. Поиск алгоритмом Кнутта-Морриса-Пратта\n7. Сохранение изменений\n0. Стоп:\t";
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
      if (n > 0)
      {
        cout << "\n\nСписок заполнен. Если хотите заполнить новый список, удалите его.";
      }
    }
    if (command == 2)
    {
      if (n > 0)
      {
        cout << "\n\n\n *****Удаление списка*****\n\n\n";
        char prompt;
        do
        {
          prompt = 'n';
          int confirm, verify;
          cout << "\n\t\t\tВы уверены, что хотите удалить список? (y/n)\t";
          cin >> prompt;
          while (prompt == 'y')
          {
            verify = std::stoi(citizen[throw_me_some_numbers(0, n-1)].passport_no);
            cout << "\nДля подтверждения удаления введите данный номер паспорта:\n\t" << verify << "\n\t";
            cin >> confirm;
            if (confirm == verify)
            {
              to_be_deleted = true;
              cout << "\n\tСписок удалён...";
              prompt = 'n';
            }
            else 
            {
             cout << "\n\tНеправильно введён номер паспорта. Повторить попытку? (y/n)\t";
             cin >> prompt;
            }
          }
        }
        while (!cin.fail() && prompt != 'n');
      }
      else { cout << "\nСписка нет."; }
    }
    if (command == 3)
    {
      if (n > 0)
      {
        char prompt;
        do
        {
          prompt = 'n';
          int int_prompt;
          bool success;
          string str2, sub;
          cout << "\n\n\n *****Поиск по паспортным данным алгоритмом Кнутта-Морриса-Пратта*****\n\n\n" << "Что вы хотите найти?\n1. Строку по серии паспорта\n2. Строку по номеру паспорта\n0. Отмена\t";
          cin >> int_prompt;
          if (int_prompt == 1)
          {
            cout << "\nВведите от 1 до 4 цифр искомой серии паспорта:\t";
            cin >> sub;
            KMP(citizen, str2, sub, success, n, int_prompt);
          }
          else if (int_prompt == 2)
          {
            cout << "\nВведите от 1 до 6 цифр искомого номера паспорта:\t";
            cin >> sub;
            KMP(citizen, str2, sub, success, n, int_prompt);
          }
          else if (int_prompt == 0)
          { prompt = 'n'; cancel = true;}
          else
          {
            cout << "\nНеправильный выбор.";
          }
          if (cancel != true)
          {
            cout << "\n\nПовторить поиск? (y/n)\t";
            cin >> prompt;
          }
          cancel = false;
        }
        while (!cin.fail() && prompt != 'n');
      }
      else { cout << "\nУ вас не заполнен список."; }
    }
    if (command == 4)
    {
      if (n > 0)
      {
        char prompt;
        do
        {
          prompt = 'n';
          int int_prompt;
          bool success;
          string str2, sub;
          cout << "\n\n\n *****Поиск по паспортным данным алгоритмом Бойера-Мура*****\n\n\n" << "Что вы хотите найти?\n1. Строку по серии паспорта\n2. Строку по номеру паспорта\n0. Отмена\t";
          cin >> int_prompt;
          if (int_prompt == 1)
          {
            cout << "\nВведите от 1 до 4 цифр искомой серии паспорта:\t";
            cin >> sub;
            for (int i = 0; i < n; i++) {
              success = BM(citizen[i].passport_region, sub, success, n, int_prompt, i, citizen);
              if (success == true) {
                cout << "\n\nПодстрока есть в строке. Элемент:\n" << citizen[i].pos << endl << citizen[i].name << endl << citizen[i].passport_region << endl << citizen[i].passport_no << endl;
                i = n;
              }
            }
              if (success != true) {
                cout << "\nПодстрока не найдена в строке.";
              }
          }
          else if (int_prompt == 2)
          {
            cout << "\nВведите от 1 до 6 цифр искомого номера паспорта:\t";
            cin >> sub;
            for (int i = 0; i < n; i++) {
              success = BM(citizen[i].passport_no, sub, success, n, int_prompt, i, citizen);
              if (success == true) {
                cout << "\n\nПодстрока есть в строке. Элемент:\n" << citizen[i].pos << endl << citizen[i].name << endl << citizen[i].passport_region << endl << citizen[i].passport_no << endl;
                i = n;
              }
            }
          }
          else if (int_prompt == 0)
          { prompt = 'n'; cancel = true;}
          else
          {
            cout << "\nНеправильный выбор.";
          }
          if (cancel != true)
          {
            cout << "\n\nПовторить поиск? (y/n)\t";
            cin >> prompt;
          }
          cancel = false;
        }
        while (!cin.fail() && prompt != 'n');
      }
      else { cout << "\nУ вас не заполнен список."; }
    }
      if (command == 7)
      {
        if (n > 0) 
        {
          save(citizen, n); 
        }
        else 
        { cout << "\nСохранить невозможно. Сначала надо заполнить список."; }
      }
      if (cancel == true) {n = -1; cancel = false;}
      if (to_be_deleted == true) {n = -1; to_be_deleted = false;}
    }
    cout << "\n\n\n\nВыход из программы...";
    return 0;
  }
