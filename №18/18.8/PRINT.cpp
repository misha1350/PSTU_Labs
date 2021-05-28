#include "PRINT.h"
#include <iostream>
#include <string>
using namespace std;
PRINT::PRINT()
{
	name = "";
	author = "";
}
PRINT::PRINT(string name, string author)
{
	this->name = name;
	this->author = author;
}
PRINT::PRINT(const PRINT& other)
{
	this->name = other.name;
	this->author = other.author;
}
void PRINT::set_name(string name)
{
	this->name = name;
}
void PRINT::set_author(string author)
{
	this->author = author;
}
PRINT& PRINT::operator=(const PRINT& other)
{
	if (&other == this)
	{
		return *this;
	}
	this->name = other.name;
	this->author = other.author;
	return *this;
}
void PRINT::Show() 
{
	cout << endl << "name:\t\t" << name;
	cout << endl << "author:\t\t" << author << endl;
}
void PRINT::Input()
{
	cout << endl << "name:\t\t";
	cin >> name;
	cout << endl << "author:\t\t";
	cin >> author;
}
void PRINT::HandleEvent(const MyEvent& e)
{
	if (e.what == mesEvent)
	{
		switch (e.command)
		{
		case cmGet:
			cout << "Èìÿ: " << get_name() << endl;
			break;
		default:
			break;
		}
	}
}