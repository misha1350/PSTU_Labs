#include "List.h"
#include <iostream>
#include <string>
#include "PRINT.h"
#include "BOOK.h"
using namespace std;
int SafeInput1(bool strict)
{
	int result;
	while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите корректное число!" << endl;
	}
	cin.get();
	return result;
}
List::~List()
{
	if (beg!=0)
	{
		delete[] beg;
		beg = nullptr;
	}
}
List::List(int size)
{
	this->size = size;
	beg = new Obj*[size];
	pos = 0;
}
void List::pushB()
{
	Obj* p;
	cout << "1) PRINT\t2)BOOK\n";
	int ch = 0;
	while (ch!=1&&ch!=2)
	{
		ch = SafeInput1(1);
		if (ch <= 0 && ch >= 3)
		{
			cout << "Введите корректное число!" << endl;
		}
	}
	if (ch == 1)
	{
		PRINT* tmp = new(PRINT);
		tmp->Input();
		p = tmp;
		if (pos < size)
		{
			beg[pos] = p;
			pos++;
			//size++;
		}
		else
		{
			cout << "\nОшибка!\n";
			return;
		}
	}
	else
	{
		BOOK* tmp = new(BOOK);
		tmp->Input();
		p = tmp;
		if (pos < size)
		{
			beg[pos] = p;///////////////////////////////////////////
			pos++;
			//size++;
		}
		else
		{
			cout << "\nОшибка!\n";
			return;
		}
	}
}
void List::show()
{
	if (size==0)
	{
		cout << "\nСписок пуст!\n";
	}
	else
	{
		Obj** tmp = beg;
		for (int i = 0; i < size; i++)
		{
			(*tmp)->Show();
			tmp++;
		}
	}
}
void List::pushB(Obj* p)
{
	if (pos < size)
	{
		beg[pos] = p;
		pos++;
	}
	else
	{
		cout << "\nОшибка!\n";
		return;
	}
}
void List::del()
{
	if (size==0)
	{
		cout << "\nСписок пуст!\n";
	}
	pos--;
	size--;
}
void List::HandleEvent(const MyEvent& e)
{
	int k = SafeInput1(1);
	if (e.what == mesEvent)
	{
		Obj** p = beg;
		for (int i = 0; i < size; i++)
		{
			if (i == k)
			{
				(*p)->HandleEvent(e);
			}
			p++;
		}
	}
}