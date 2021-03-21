#include <iostream>
#include <cmath>
#include "coordinates.h"
using namespace std;

void coordinates::init(double A, double B)
{
	first = A; second = B;
}
void coordinates::read(int i)
{
	cout << "\n¬ведите " << i << "-й X: "; cin >> first;
	cout << "¬ведите " << i << "-й Y: "; cin >> second;
}
void coordinates::print(int i)
{
	cout << "\nX" << i << " = " << first;
	cout << "\tY" << i << " = " << second;
}
double coordinates::distance(coordinates xy, coordinates x1y1)
{
	double result;
	result = sqrt(pow(x1y1.first - xy.first, 2) + pow(x1y1.second - xy.second, 2));
	return abs(result);
}
