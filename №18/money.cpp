#include <iostream>
#include "money.h"

using namespace std;

/*
Вариант 9 (19)
Два поля - long для рублей и int для копеек. Дробная часть отделяется запятой. Реализовать:
- вычитание дробного числа из суммы
- операции сравнения (==, !=)
*/

//Перегрузка операции присваивания
money& money::operator=(const money& t)
{
	//Проверка на самоприсваивание
	if (&t == this)
		return *this;
	ruble = t.ruble;
	kopeck = t.kopeck;
	return *this;
}
//Перегрузка префиксной операции инкремент
money& money::operator++()
{
	long temp = ruble * 100 + kopeck;
	temp++;
	ruble = temp / 100;
	kopeck = temp % 100;
	return *this;
}
//Перегрузка постфиксной операции инкремент
money money::operator++ (int)
{
	long temp = ruble * 100 + kopeck;
	temp++;
	money t(ruble, kopeck);
	ruble = temp / 100;
	kopeck = temp % 100;
	return t;
}
//Перегрузка бинарной операции сложения
money money::operator+ (const money& t)
{
	long temp1 = ruble * 100 + kopeck;
	long temp2 = t.ruble * 100 + t.kopeck;
	money add;
	add.ruble = (temp1 + temp2) / 60;
	add.kopeck = (temp1 + temp2) % 60;
	return add;
}
//Перегрузка глобальной функции-операции ввода
istream& operator>> (istream& in, money& t)
{
	cout << "\nВведите рубли: "; in >> t.ruble;
	cout << "\nВведите копейки: "; in >> t.kopeck;
	return in;
}
ostream& operator<< (ostream& out, const money& t)
{
	return (out << t.ruble << " : " << t.kopeck);
}