#include <iostream>
#include <stdio.h>
#include <string>
#include "ClassRational.h"

Rational::Rational(const Rational& r)
{
	n = r.n;
	m = r.m;
}
Rational::Rational(int n1, int m1)
{
	if (m1 < 0)
	{
		n1 = -n1;
		m1 = -m1;
	}
	if (m1 == 0)
	{
		n = 0;
		m = 1;
	}
	else
	{
		n = n1;
		m = m1;
		Reduction();
	}
}
Rational::~Rational()
{
	n = 0;
	m = 0;
}
void Rational::Reduction()
{
	unsigned int i = 2;
	while (i <= m)
	{
		if (m % i == 0 && n % i == 0)
		{
			n = n / i;
			m = m / i;
			i = 2;
		}
		else
			++i;
	}
	return;
}
int Rational::getN()
{
	return n;
}
int Rational::getM()
{
	return m;
}
string Rational::getFraction()
{
	if (m == 0)
		return "4islo ne zadano";
	if (m == 1)
		return to_string(n);
	else
		return to_string(n) + '/' + to_string(m);
}
Rational& Rational::operator = (const Rational& r)
{
	n = r.n;
	m = r.m;
	return *this;
}
Rational Rational::operator + (const Rational& r)
{
	Rational result;
	if (m == r.m)
	{
		result.n = n + r.n;
		result.m = m;
		result.Reduction();
		return result;
	}
	else
	{
		result.n = n * r.m + r.n * m;
		result.m = m * r.m;
		result.Reduction();
		return result;
	}
}
Rational Rational::operator - (const Rational& r)
{
	Rational result;
	if (m == r.m)
	{
		result.n = n - r.n;
		result.m = m;
		result.Reduction();
		return result;
	}
	else
	{
		result.n = n * r.m - r.n * m;
		result.m = m * r.m;
		result.Reduction();
		return result;
	}
}
Rational Rational::operator * (const Rational& r)
{
	Rational result;
	result.n = n * r.n;
	result.m = m * r.m;
	result.Reduction();
	return result;
}
Rational Rational::operator / (const Rational& r)
{
	Rational result;
	result.n = n * r.m;
	result.m = m * r.n;
	result.Reduction();
	return result;
}

bool Rational::operator == (const Rational& r)
{
	if (n == r.n && m == r.m)
		return true;
	else
		return false;
}
bool Rational::operator < (const Rational& r)
{
	if (n * r.m - r.n * m < 0)
		return true;
	else
		return false;
}
bool Rational::operator > (const Rational& r)
{
	if (n * r.m - r.n * m > 0)
		return true;
	else
		return false;
}
bool Rational::operator <= (const Rational& r)
{
	if (n * r.m - r.n * m <= 0)
		return true;
	else
		return false;
}
bool Rational::operator >= (const Rational& r)
{
	if (n * r.m - r.n * m >= 0)
		return true;
	else
		return false;
}
bool Rational::operator != (const Rational& r)
{
	if (n == r.n && m == r.m)
		return false;
	else
		return true;
}

ostream & operator << (ostream & stream, const Rational& r)
{
	stream << to_string(r.n) + '/' + to_string(r.m);
	return stream;
}
istream & operator >> (istream & stream, Rational& r)
{
	stream >> r.n >> r.m;
	r.Reduction();
	return stream;
}