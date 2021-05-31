#pragma once
#include <iostream>
#include<vector>
using namespace std;
template <class T>
class container
{
public:
    container(int size)
    {
        this->size = size;
        data = new T[size];
    }
    container(const container& obj)
    {
        this->size = obj.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = obj.data[i];
        }
    }
    ~container()
    {
        delete[] data;
        data = nullptr;
    }
    container<T>& operator = (const container<T>& obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        this->size = obj.size;
        if (data != 0)
        {
            delete[]data;
        }
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = obj.data[i];
        }
        return *this;
    }
    T& operator [] (const int index)
    {
        if (index < size)
        {
            return data[index];
        }
        else
        {
            cout << "\nОшибка!";
        }
    }
    bool operator != (const container& obj)
    {
        if (this->size == obj.size)
        {
            bool tmp = false;
            for (int i = 0; i < size; i++)
            {
                if (data[i] != obj.data[i])
                {
                    tmp = true;
                }
            }
            return tmp;
        }
        else
        {
            return true;
        }
    }
    bool operator < (const int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == value)
            {
                return true;
            }
        }
        return false;
    }
    void show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << "   ";
        }
        cout << endl;
    }
    void PushMax()
    {
        T max(0, 0);
        for (int i = 0; i < size; i++)
        {
            if (max <data[i])
            {
                max = data[i];
            }
        }
        container<T> tmp(size + 1);
        for (int i = 0; i < size; i++)
        {
            tmp[i]=data[i];
        }
        tmp[size] = max;
        delete[] data;
        data = nullptr;
        this->size = tmp.size;
        data = new T[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = tmp[i];
        }
    }
    void delKey(T key)
    {
        vector<T> tmp;
        bool f = 0;
        for (int i = 0; i < size; i++)
        {
            if (data[i]!=key)
            {
                tmp.push_back(data[i]);
            }
            else
            {
                f = 1;
            }
        }
        if (f == 1)
        {
            delete[] data;
            data = nullptr;
            this->size = tmp.size();
            data = new T[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = tmp[i];
            }
        }
        else
        {
            cout << "\nОшибка удаления!\n";
        }
    }
    void AVG()
    {
        T sum(0, 0);
        T avg(0, 0);
        for (int i = 0; i < size; i++)
        {
            sum = sum + data[i];
        }
        avg = sum / size;
        cout << "\nСреднее арифметическое: " << avg << endl;
        for (int i = 0; i < size; i++)
        {
            data[i] = data[i] + avg;
        }
    }
    friend ostream& operator<< (ostream& out, const container<T>& other)
    {
        for (int i = 0; i < other.size; i++)
        {
            out << other.data[i] << "  ";
        }
        return out;
    }
    friend istream& operator>> (istream& in, container<T>& other)
    {
        for (int i = 0; i < other.size; i++)
        {
            cout << "\nВведите параметр:\t";
            in >> other.data[i];
        }
        return in;
    }

private:
    int size;
    T* data;

};
