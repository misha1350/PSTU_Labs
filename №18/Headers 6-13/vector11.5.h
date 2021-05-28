#pragma once
#include<iostream>
#include <stack>
using namespace std;
template <typename Type>
class vector5
{
	stack<Type> container;
	int s;
public:
	vector5() { s = 0; };

	vector5(int n)
	{
		Type obj;
		for (int i = 0; i < n; i++) {
			obj = ((rand() % 100) * 0.1);
			container.push(obj);
		}
		s = container.size();
	}

	void Print()
	{
		stack<Type>temp;
		temp = container;
		while (!temp.empty()) {
			cout << temp.top() << "; ";
			temp.pop();
		}
		cout << endl;
	}

	vector5 operator+(const Type newElement)
	{
		vector5<Type>tmp;
		//stack<int>temp, temp2;
		for (int i = 0; i < s; i++) {
			container.top() += newElement;
			tmp.container.push(container.top());
			container.pop();
		}
		return tmp;
	}

	int get_size()
	{
		return s;
	}

	int find_mean()
	{
		int length = s;
		stack<Type>tmp = container;
		int mean2 = 0, count = 0;
		for (int i = 0; i < length; i++) {
			mean2 += tmp.top();
			count++;
			tmp.pop();
		}
		mean2 = mean2 / count;
		return mean2;
	}
};
