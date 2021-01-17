#include <iostream>
#include<time.h>
using namespace std;

int main()
{
	int size = -1;
	int x1, x2,k=0;
	string typeFill = "word";
	while (size <= 0)
	{
		cout << "Input array size: \n";
		cin >> size;
	}
	int* arr = new int[size];
	cout << "Fill out the array randomly? (y/n)\n";
	while (typeFill != "y" && typeFill != "n")
	{
		cin >> typeFill;
		if (typeFill != "y" && typeFill != "n")
		{
			cout << "Come again?\n";
		}
	}
	if (typeFill == "n")
	{
		cout << "Fill out the array with " << size << " elements:\n";
		for (int i = 0; i < size; i++)
		{
      cout << i+1 << ". ";
			cin >> arr[i];
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 20;
		}
	}
	cout << "Array elements right to left:\n";
	for (int i = size-1; i >= 0; i--)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n\n";
	size += 2;
	for (int i = size - 2; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}
	cout << "Input the value of the new first array element: ";
	cin >> x1;
	cout << "\nInput the value of the new last array element: ";
	cin >> x2;
	cout << "\n";
	arr[0] = x1;
	arr[size - 1] = x2;
	for (int j = 0; j < size; j++)
	{
		if (arr[j]%2!=0)
		{

			for (int i = j; i < size; i++)
			{
				arr[i] = arr[i + 1];
			}
			size--;
			j = 0;
			if (size - 1 == j)
			{
				size-=2;
			}
		}
	}
	cout << "\nNew array w/out elements with odd values:\n";
	for (int l = size - 1; l >= 0; l--)
	{
		cout << arr[l] << "\t";
	}
}
