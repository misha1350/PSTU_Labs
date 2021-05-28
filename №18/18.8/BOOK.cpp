#include "Book.h"
#include <iostream>
#include <string>
using namespace std;
int SafeInput(bool strict)
{
	int result;
	while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "¬ведите корректное число!" << endl;
	}
	cin.get();
	return result;
}
BOOK::BOOK()
{
	quanP = 0;
	publish = "";
}
BOOK::BOOK(int quanP, int Group, string publish, string name, string author) :PRINT(name, author)
{
	this->quanP = quanP;
	this->publish = publish;
}
BOOK::BOOK(const BOOK& other)
{
	this->name = other.name;
	this->author = other.author;
	this->quanP = other.quanP;
	this->publish = other.publish;
}
BOOK& BOOK::operator=(const BOOK& other)
{
	this->name = other.name;
	this->author = other.author;
	this->quanP = other.quanP;
	this->publish = other.publish;
	return *this;
}
void BOOK::Show()
{
	cout << endl << "name:\t\t\t" << name;
	cout << endl << "author:\t\t\t" << author;
	cout << endl << "publish:\t\t" << publish;
	cout << endl << "number of pages:\t" << quanP;
}
void BOOK::Input()
{
	cout << "name:\t\t\t"; cin >> name;
	cout << "author:\t\t\t"; cin >> author;
	cout << "publish:\t\t"; cin >> publish;
	cout << "number of pages:\t";
	quanP = SafeInput(1);
}
