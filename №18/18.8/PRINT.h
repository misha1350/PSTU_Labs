#pragma once
#include <iostream>
#include <string>
#include "Obj.h"
#include "Event.h"
using namespace std;
class PRINT: public Obj
{
public:
	PRINT();
	PRINT(string name, string author);
	PRINT(const PRINT& other);
	void set_name(string name);
	void set_author(string author);
	string get_name() { return name; }
	string get_author() { return author; }
	PRINT& operator = (const PRINT& other);
	void Show() override;
	void Input() override;
	void HandleEvent(const MyEvent& e);
protected:
	string name;
	string author;
};

