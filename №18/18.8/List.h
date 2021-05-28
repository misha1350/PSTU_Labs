#pragma once
#include "Obj.h"
#include "Event.h"
class List
{
public:
	List(int size);
	~List();
	void pushB();
	void pushB(Obj* p);
	void del();
	void show();
	int sizeList() { return size; }
	void HandleEvent(const MyEvent& e);
protected:
	int size;
	Obj** beg;
	int pos;
};

