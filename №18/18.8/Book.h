#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Print.h"
class Book :public Print
{
public:
	Book();
	Book(int quantity, int Group, string publish, string name, string author);
	Book(const Book& other);
	int get_quantity() { return quantity; }
	string get_publish() { return publish; }
	void set_quantity(int quantity) { this->quantity = quantity; }
	void set_publish(string publish) { this->publish = publish; }
	Book& operator = (const Book& other);
	void Show() override;
	void Input() override;
private:
	int quantity;
	string publish;
};

