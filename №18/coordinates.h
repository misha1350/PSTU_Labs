#pragma once
// ���� first - ������� ����� x, ���������� �����, ���� second - ������� ����� y, ���������� �����.����������� ����� distance(double x1, double y1) - ���������� ���������� �� ����� � ������������(first, second) �� ����� � ������������(x1, y1).

class coordinates {
public:
	double first; // ���������� x
	double second; //���������� y
	void init(double A, double B);
	void read(int i);
	void print(int i);
	double distance(coordinates xy, coordinates x1y1);
};