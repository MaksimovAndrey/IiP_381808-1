#include <iostream>
#include <stdio.h>
#include <string>
#include "ClassRational.h"
using namespace std;
/*
1. Рациональное число
Разработать класс Rational (рациональное число).
Класс должен хранить корректные дроби n/m (знаменатель не равен 0).
Дробь должна храниться в несократимом виде.
Класс должен содержать все необходимые конструкторы и деструктор.
В классе должны быть перегружены операции:
* присваивания;
* 4 стандартные арифметические операции;
* сравнения;
* ввода/вывода в поток.
*/

int main()
{
	Rational r = Rational(2, 4);
	cout << "konstructor iz dvyh 4isel + cokrashenie drobi\n" << "Doljno bit: 1/2\n" << "Poluchilos': " << r.getFraction() << "\n\n";

	r.~Rational();
	cout << "destructor\n" << "Doljno bit: 4islo ne zadano\n" << "Poluchilos': " << r.getFraction() << "\n\n";

	r = Rational();
	cout << "standartniy konstructor\n" << "Doljno bit: 0\n" << "Poluchilos': " << r.getFraction() << "\n\n";

	r = Rational(15);
	cout << "konstructor celogo 4isla\n" << "Doljno bit: 15\n" << "Poluchilos': " << r.getFraction() << "\n\n";

	r = Rational(4, 7);
	cout << "4islitel' + znamenatel'\n" << "Doljno bit: 4 7\n" << "Poluchilos': " << r.getN() << ' ' << r.getM() << "\n\n";

	Rational r1 = r;
	cout << "=\n" << "Doljno bit: 4/7\n" << "Poluchilos': " << r1.getFraction() << "\n\n";

	r1 = r1 + r;
	cout << "+\n" << "Doljno bit: 8/7\n" << "Poluchilos': " << r1.getFraction() << "\n\n";

	r1 = r1 - r;
	cout << "-\n" << "Doljno bit: 4/7\n" << "Poluchilos': " << r1.getFraction() << "\n\n";

	r1 = r1 * r;
	cout << "*\n" << "Doljno bit: 16/49\n" << "Poluchilos': " << r1.getFraction() << "\n\n";

	r1 = r1 / r;
	cout << "/\n" << "Doljno bit: 4/7\n" << "Poluchilos': " << r1.getFraction() << "\n\n";

	cout << ">\n" << "Doljno bit: 0\n" << "Poluchilos': " << (r1 > r) << "\n\n";

	cout << "<\n" << "Doljno bit: 0\n" << "Poluchilos': " << (r1 < r) << "\n\n";

	cout << "==\n" << "Doljno bit: 1\n" << "Poluchilos': " << (r1 == r) << "\n\n";

	cout << ">=\n" << "Doljno bit: 1\n" << "Poluchilos': " << (r1 >= r) << "\n\n";

	cout << "<=\n" << "Doljno bit: 1\n" << "Poluchilos': " << (r1 <= r) << "\n\n";

	cout << "!=\n" << "Doljno bit: 0\n" << "Poluchilos': " << (r1 != r) << "\n\n";

	cout << "<<\n" << "Doljno bit: 4/7\n" << "Poluchilos': " << r1 << "\n\n";

	cout << ">>\nVvedite drob': ";
	cin >> r1;
	cout << "Poluchilos': " << r1 << "\n\n";

	getchar();
	getchar();
	return 0;
}