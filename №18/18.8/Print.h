#pragma once
#include <iostream>
#include <string>
#include "Obj.h"
#include "Event.h"
using namespace std;
class Print: public Obj
{
public:
	Print();
	Print(string name, string author);
	Print(const Print& other);
	void set_name(string name);
	void set_author(string author);
	string get_name() { return name; }
	string get_author() { return author; }
	Print& operator = (const Print& other);
	void Show() override;
	void Input() override;
	void HandleEvent(const MyEvent& e);
protected:
	string name;
	string author;
};

