#pragma once
const int mesNothing = 0;
const int mesEvent = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 5;
const int cmShowN = 6;
const int cmQuit = 101;
struct MyEvent
{
	int what;				//��� �������
	union 
	{
		int command;		//��� �������
		struct 
		{
			int message;
			int a;			//��������� �������
		};
	};
};