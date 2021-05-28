#include "Dialog.h"
#include <iostream>
#include <string>
using namespace std;
Dialog::Dialog(int size):List(size)
{
	Stat = 0;
}
Dialog::~Dialog()
{
}
void Dialog::GetE(MyEvent& event)
{
	string ALLin = "+-s/qamz";
	string s;
	string par;
	char code;
	cout << "\n¬ведите параметр: ";
	cin >> s;
	code = s[0];
	if (ALLin.find(code) >= 0)
	{
		event.what = mesEvent;
		switch (code)
		{
		case'm':
			event.command = cmMake;
			break;
		case'+':
			event.command = cmAdd;
			break;
		case '-':
			event.command = cmDel;
			break;
		case 's':
			event.command = cmShow;
			break;
		case 'q':
			event.command = cmQuit;
			break;
		case 'z':
			event.command = cmGet;
			break;
		default:
			break;
		}
		if (s.length() > 1)
		{
			par = s.substr(1, s.length() - 1);
			int A = atoi(par.c_str());
			event.a = A;
		}
	}
	else
	{
		event.what = mesNothing;
	}
}
int Dialog::Execute()
{
	MyEvent event;
	do
	{
		Stat = 0;
		GetE(event);
		Handle(event);
	} while (!Valid());
	return Stat;
}
int Dialog::Valid()
{
	if (Stat == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void Dialog::Clear(MyEvent& event)
{
	event.what = mesNothing;
}
void Dialog::END()
{
	Stat = 1;
}
void Dialog::Handle(MyEvent& event)
{
	if (event.what==mesEvent)
	{
		switch (event.command)
		{
		case cmMake:
			cin >> event.a;
			size = event.a;
			beg = new Obj * [size];
			pos = 0;
			Clear(event);
			break;
		case cmAdd:
			pushB();
			Clear(event);
			break;
		case cmDel:
			del();
			Clear(event);
			break;
		case cmShow:
			cout << endl;
			show();
			cout << endl;
			Clear(event);
			break;
		case cmQuit:
			Clear(event);
			break;
		case cmGet:
			List::HandleEvent(event);
			Clear(event);
			break;
		default:
			break;
		}
	}
}