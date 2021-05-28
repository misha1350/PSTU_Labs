#include "Print.h"
#include <iostream>
#include <string>
using namespace std;
Print::Print()
{
	name = "";
	author = "";
}
Print::Print(string name, string author)
{
	this->name = name;
	this->author = author;
}
Print::Print(const Print& other)
{
	this->name = other.name;
	this->author = other.author;
}
void Print::set_name(string name)
{
	this->name = name;
}
void Print::set_author(string author)
{
	this->author = author;
}
Print& Print::operator=(const Print& other)
{
	if (&other == this)
	{
		return *this;
	}
	this->name = other.name;
	this->author = other.author;
	return *this;
}
void Print::Show() 
{
	cout << endl << "name:\t\t" << name;
	cout << endl << "author:\t\t" << author << endl;
}
void Print::Input()
{
	cout << endl << "name:\t\t";
	cin >> name;
	cout << endl << "author:\t\t";
	cin >> author;
}
void Print::HandleEvent(const MyEvent& e)
{
	if (e.what == mesEvent)
	{
		switch (e.command)
		{
		case cmGet:
			cout << "Имя: " << get_name() << endl;
			break;
		default:
			break;
		}
	}
}
