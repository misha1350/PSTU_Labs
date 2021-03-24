/*
Выполнить сортировки методом Шелла и методом Хоара в соответствии со своим вариантом.

19. Дан список рек и их длины. Упорядочить по убыванию длин
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct list
{
    string river;
    int river_length;
};

enum menu {
  Shell = 1,
  Quick
};

void fill_out(vector<list>& river_systems, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nВведите название реки №" << i + 1 << ":\t";
        cin.ignore();
        getline(cin, river_systems[i].river);
        cout << "Введите длину реки №" << i + 1 << " целым числом в километрах:\t";
        cin >> river_systems[i].river_length;
    }
}

void Shellsort(vector<list>& river_systems, int n)
{
    string temp1;
    int temp2, j;
    for (int step = n / 2; step > 0; step /= 2)
    {
        for (int i = step; i < n; i++)
        {
            temp1 = river_systems[i].river;
            temp2 = river_systems[i].river_length;
            for (j = i; j >= step; j -= step)
            {
                if (temp2 > river_systems[j - step].river_length)
                {
                    river_systems[j].river = river_systems[j - step].river;
                    river_systems[j].river_length = river_systems[j - step].river_length;
                }
                else
                {
                    j = step;
                }
            }
            river_systems[j].river = temp1;
            river_systems[j].river_length = temp2;
        }
    }
}

void Quicksort(vector<list>& river_systems, int left, int right)
{
    int d;
    string f;
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (river_systems[i].river_length > river_systems[(left + right) / 2].river_length && i < right)
            i++;
        while (river_systems[j].river_length < river_systems[(left + right) / 2].river_length && j > left)
            j--;
        if (i <= j)
        {
            d = river_systems[i].river_length;
            river_systems[i].river_length = river_systems[j].river_length;
            river_systems[j].river_length = d;
            f = river_systems[i].river;
            river_systems[i].river = river_systems[j].river;
            river_systems[j].river = f;
            i++;
            j--;
        }
        if (i < right)
        {
            Quicksort(river_systems, i, right);
        }
        if (j > left)
        {
            Quicksort(river_systems, left, j);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int n = 0;
    while (n < 1)
    {
        cout << "\nВведите кол-во элементов списка:\t";
        cin >> n;
    }
    vector<list> river_systems(n);

    fill_out(river_systems, n);

    cout << "Каким методом сортировать (длины рек по убыванию)?\n\t1.Методом Шелла\n\t2.Методом Хоара\n";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case Shell:
    {
        Shellsort(river_systems, n);
        cout << "\n\nРезультат:";
        for (int i = 0; i < n; i++)
        {
            cout << "\n\n" << i + 1 << ".\nНазвание реки:\t" << river_systems[i].river << "\nДлина реки:\t" << river_systems[i].river_length;
        }
        break;
    }
    case Quick:
    {
        Quicksort(river_systems, 0, n - 1);
        cout << "\n\nРезультат:";
        for (int i = 0; i < n; i++)
        {
            cout << "\n\n" << i + 1 << ".\nНазвание реки:\t" << river_systems[i].river << "\nДлина реки:\t" << river_systems[i].river_length;
        }
        break;
    }
    default:
    { cout << "\n\nНеопознанная команда!"; break; }
    }
    return 0;
}
