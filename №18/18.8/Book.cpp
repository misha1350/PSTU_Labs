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
		cout << "Введите корректное число!" << endl;
	}
	cin.get();
	return result;
}
Book::Book()
{
	quantity = 0;
	publish = "";
}
Book::Book(int quantity, int Group, string publish, string name, string author) :Print(name, author)
{
	this->quantity = quantity;
	this->publish = publish;
}
Book::Book(const Book& other)
{
	this->name = other.name;
	this->author = other.author;
	this->quantity = other.quantity;
	this->publish = other.publish;
}
Book& Book::operator=(const Book& other)
{
	this->name = other.name;
	this->author = other.author;
	this->quantity = other.quantity;
	this->publish = other.publish;
	return *this;
}
void Book::Show()
{
	cout << endl << "name:\t\t\t" << name;
	cout << endl << "author:\t\t\t" << author;
	cout << endl << "publish:\t\t" << publish;
	cout << endl << "number of pages:\t" << quantity;
}
void Book::Input()
{
	cout << "name:\t\t\t"; cin >> name;
	cout << "author:\t\t\t"; cin >> author;
	cout << "publish:\t\t"; cin >> publish;
	cout << "number of pages:\t";
	quantity = SafeInput(1);
}
