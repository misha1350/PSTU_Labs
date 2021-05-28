#pragma once
#include "List.h"
#include "Event.h"
#include <string>
class Dialog:public List
{
public:
	Dialog(int size);
	~Dialog();
	virtual void GetE(MyEvent& event);
	virtual int Execute();
	virtual void Handle(MyEvent& event);
	virtual void Clear(MyEvent& event);
	int Valid();
	void END();
protected:
	int Stat;
};

