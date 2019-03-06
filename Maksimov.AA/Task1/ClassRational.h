#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Rational
{
private:
	signed int n; // 4islitel'
	unsigned int m; // znamenatel'
public:
	Rational(); // standartniy konstructor
	Rational(int n1, int m1); // konstructor iz dvyh 4isel
	Rational(int n1); // konstructor celogo 4isla

	void Reduction(); // sokrashenie drobi
	int getN(); // zapros 4islitel9
	int getM(); // zapros znamenatel9
	string getFraction(); // zapros racional'nogo 4isla

	Rational operator = (const Rational& r); // =
	Rational operator + (const Rational& r); // +
	Rational operator - (const Rational& r); // -
	Rational operator * (const Rational& r); // *
	Rational operator / (const Rational& r); // / 

	friend ostream & operator << (ostream & stream, Rational& r); // vivod
	friend istream & operator >> (istream & stream, Rational& r); // vvod

	bool operator == (const Rational& r); // ==
	bool operator < (const Rational& r);  // <
	bool operator > (const Rational& r);  // > 
	bool operator <= (const Rational& r); // <=
	bool operator >= (const Rational& r); // >=
	bool operator != (const Rational& r); // !=

	~Rational(); // destructor
};