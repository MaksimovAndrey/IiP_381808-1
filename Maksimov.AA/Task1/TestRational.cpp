#include <iostream>
#include <stdio.h>
#include <string>
#include "ClassRational.h"
using namespace std;

int main()
{
	Rational r(2, 4);
	cout << "konstructor iz dvyh 4isel + cokrashenie drobi\n" << "Doljno bit: 1/2\n" << "Poluchilos': " << r.getFraction() << "\n\n";

	Rational r1;
	cout << "konstructor po umolchaniu\n" << "Doljno bit: 0\n" << "Poluchilos': " << r1.getFraction() << "\n\n";

	Rational r2(15);
	cout << "konstructor preobrazovani9 tipa\n" << "Doljno bit: 15\n" << "Poluchilos': " << r2.getFraction() << "\n\n";

	Rational r3(4, 7);
	cout << "konstructor inicializator\n" << "Doljno bit: 4 7\n" << "Poluchilos': " << r3.getN() << ' ' << r3.getM() << "\n\n";

	Rational r4(r);
	cout << "konstructor inicializator\n" << "Doljno bit: 1 2\n" << "Poluchilos': " << r4.getN() << ' ' << r4.getM() << "\n\n";

	
	r1 = r3;
	cout << "=\n" << "Doljno bit: 4/7\n" << "Poluchilos': " << r1.getFraction() << "\n\n";

	r1 = r1 + r3;
	cout << "+\n" << "Doljno bit: 8/7\n" << "Poluchilos': " << r1.getFraction() << "\n\n";

	r1 = r1 - r3;
	cout << "-\n" << "Doljno bit: 4/7\n" << "Poluchilos': " << r1.getFraction() << "\n\n";

	r1 = r1 * r3;
	cout << "*\n" << "Doljno bit: 16/49\n" << "Poluchilos': " << r1.getFraction() << "\n\n";

	r1 = r1 / r3;
	cout << "/\n" << "Doljno bit: 4/7\n" << "Poluchilos': " << r1.getFraction() << "\n\n";

	cout << ">\n" << "Doljno bit: 0\n" << "Poluchilos': " << (r1 > r3) << "\n\n";

	cout << "<\n" << "Doljno bit: 0\n" << "Poluchilos': " << (r1 < r3) << "\n\n";

	cout << "==\n" << "Doljno bit: 1\n" << "Poluchilos': " << (r1 == r3) << "\n\n";

	cout << ">=\n" << "Doljno bit: 1\n" << "Poluchilos': " << (r1 >= r3) << "\n\n";

	cout << "<=\n" << "Doljno bit: 1\n" << "Poluchilos': " << (r1 <= r3) << "\n\n";

	cout << "!=\n" << "Doljno bit: 0\n" << "Poluchilos': " << (r1 != r3) << "\n\n";

	cout << "<<\n" << "Doljno bit: 4/7\n" << "Poluchilos': " << r1 << "\n\n";

	cout << ">>\nVvedite drob': ";
	cin >> r1;
	cout << "Poluchilos': " << r1 << "\n\n";

	getchar();
	getchar();
	return 0;
}