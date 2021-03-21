#pragma once
// Поле first - дробное число x, координата точки, поле second - дробное число y, координата точки.Реализовать метод distance(double x1, double y1) - вычисление расстояния от точки с координатами(first, second) до точки с координатами(x1, y1).

class coordinates {
public:
	double first; // координата x
	double second; //координата y
	void init(double A, double B);
	void read(int i);
	void print(int i);
	double distance(coordinates xy, coordinates x1y1);
};