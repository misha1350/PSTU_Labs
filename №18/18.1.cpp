/*
9 вариант (19 вариант)
Поле first - дробное число x, координата точки , поле second - дробное число y, координата точки. Реализовать метод distance(double x1, double y1) - вычисление расстояния от точки с координатами (first, second) до точки с координатами (x1, y1).
*/
#include <iostream>
#include <cmath>
#include "coordinates.h"

using namespace std;

coordinates make_coordinates(double F, double S)
{
	coordinates t;
	t.init(F, S);
	return t;
}

int main() 
{
	setlocale(LC_ALL, "ru");
	//double A, B;
	coordinates xy;
	coordinates x1y1;
	int i = 1;
	cout << "(Для получения нормального расстояния между точками x, y и x1, y1 введите координаты 10, 34 и 3, 10)\n";
	xy.init(20, 2);
	xy.read(i); i++;
	x1y1.read(i); i = 1;
	xy.print(i); i++;
	x1y1.print(i); i = 1;
	cout << "\nРасстояние между точками (" << xy.first << ", " << xy.second << ") и (" << x1y1.first << ", " << x1y1.second << ") = " << xy.distance(xy, x1y1) << endl;
}
