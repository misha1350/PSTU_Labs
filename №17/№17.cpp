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

// void save(vector<str> citizen, int n)
// {
//   string save_name;
//   cout << "Введите название файла для сохранения...\t";
//   cin >> save_name; 
//   save_name += ".txt";
//   ofstream save(save_name);
//   for (int i = 0; i < n; i++)
//   {
//     save << endl << citizen[i].pos << "." << endl;
//     save << citizen[i].name << endl ;
//     save << citizen[i].passport_region << endl;
//     save << citizen[i].passport_no << endl;
//   }
//   save.close();
//   cout << "\nФайл сохранён.";
// }

class HashT
{
public:
    int key;
    vector<str>list;
    void HashF(string one, string two, int N)
    {
        int int1 = stoi(one);
        int int2 = stoi(two);
        int tmp = int1 + int2; 
        double A = 0.618033;
        key = N * fmod(tmp * A, 1);
    }
    void Add(str hum)
    {
        list.push_back(hum);
    }
};
void hashSort(vector<HashT>& list)
{
    for (int step = list.size() / 2; step > 0; step /= 2)
    {
        for (int i = step; i < list.size(); i++)
        {
            for (int j = i; j >= step; j -= step)
            {
                if (list[j].key < list[j - step].key)
                    swap(list[j], list[j - step]);
            }
        }
    }
}
void FillHash(vector<HashT>& list, vector<str> citizen)
{
    for (int i = 0; i < citizen.size(); i++)
    {
        HashT tmp;
        tmp.HashF(citizen[i].passport_region, citizen[i].passport_no, citizen.size());
        tmp.Add(citizen[i]);
        list.push_back(tmp);
    }
    hashSort(list);
    int size = list.size();
    for (int i = 0; i < size - 1;)
    {
        if (list[i].key == list[i + 1].key)
        {
            list[i].list.push_back(list[i + 1].list[0]);
            list.erase(list.begin() + i + 1);
            size--;
        }
        else
            i++;
    }
}
void ShowHash(vector<HashT> list)
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << "-----------------------------------------------------------------------\n";
        cout << "Хеш: " << i + 1 << list[i].key << endl;
        for (int j = 0; j < list[i].list.size(); j++)
        {
            cout << "\nПозиция:\t" << list[i].list[j].pos;
            cout << "\nИмя:\t\t" << list[i].list[j].name;
            cout << "\nПаспорт:\t" << list[i].list[j].passport_region << " " << list[i].list[j].passport_no << "\n";
        }
    }
}

int main()
{
  setlocale(LC_ALL, "ru");  
  vector<str> citizen;
    int n1 = 0;
    cout << "Введите количество элементов(не менее 5): ";
    while (n1 < 5)
    {
        cin >> n1;
        if (n1 < 5)
        {
            cout << "Введено некоректное значение. Введите значение заново";
        }
    }
    fill_out(citizen, n1);
    print(citizen, n1);
    cout << "\n\n";
    vector<HashT>list;
    FillHash(list, citizen);
    cout << "\n\tХеш таблица:" << endl;
    ShowHash(list);
    cout << endl;
  return 0;
}
