#pragma once
#include <iostream>
#include <string>
using namespace std;

struct node
{
	string data;
	node* prev;
};
class Str
{
private:
		node* top;;
public:
	string Top();
	Str();
	~Str();
	void push(string data);
	void pop();
	void Print();
	int size();
};

string Str::Top() {
	return top->data;
}

Str::Str() {
	top = nullptr;
}

Str::~Str() {
	while (top)
	{
		node* pv = top;
		top = top->prev;
		delete pv;
	}
}

void Str::push(string data)
{
	node* pv = new node;
	pv->data = data;
	pv->prev = top;
	top = pv;
}

void Str::pop()
{
	if (!(top == nullptr))
	{
		string tmp = top->data;
		node* pv = top;
		top = top->prev;
		delete pv;
	}
}

int Str::size()
{
	int size = 0;
	while (top)
	{
		node* pv = top;
		top = top->prev;
		size++;
	}
	return size;
}

void Str::Print()
{
	node* pv = top;
	while (top)
	{
		cout << top->data << ' ';
		top = top->prev;
	}
	top = pv;
	cout << endl;
}
