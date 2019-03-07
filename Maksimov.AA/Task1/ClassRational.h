#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Rational
{
private:
	signed int n = 0; // 4islitel'
	unsigned int m = 1; // znamenatel'
public:
	Rational() {}; // konstructor po umolchaniu
	Rational(int n1, int m1); // konstructor inicializator
	Rational(int n1) : n(n1) {}; // konstructor preobrazovani9 tipa
	Rational(const Rational& r); // konstructor kopirovani9

	~Rational(); // destructor

	void Reduction(); // sokrashenie drobi
	int getN(); // zapros 4islitel9
	int getM(); // zapros znamenatel9
	string getFraction(); // zapros racional'nogo 4isla

	Rational& operator = (const Rational& r); // =
	Rational operator + (const Rational& r); // +
	Rational operator - (const Rational& r); // -
	Rational operator * (const Rational& r); // *
	Rational operator / (const Rational& r); // / 

	friend ostream & operator << (ostream & stream, const Rational& r); // vivod
	friend istream & operator >> (istream & stream, Rational& r); // vvod

	bool operator == (const Rational& r); // ==
	bool operator < (const Rational& r);  // <
	bool operator > (const Rational& r);  // > 
	bool operator <= (const Rational& r); // <=
	bool operator >= (const Rational& r); // >=
	bool operator != (const Rational& r); // !=
};