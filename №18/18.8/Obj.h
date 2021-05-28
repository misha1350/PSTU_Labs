#pragma once
#include"Event.h"
class Obj
{
public:
	Obj();
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual void HandleEvent(const MyEvent& e) = 0;
	virtual ~Obj();
};

