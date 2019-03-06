#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

class Triangle
{
public:
	double a, b, c;
	double perimeter, area;
	int existence, type;
	Triangle(double _a, double _b, double _c); // c - диагональ
	Triangle();
	~Triangle();
};
Triangle::Triangle()
{
	a = 0.0;
	b = 0.0;
	c = 0.0;
	perimeter = 0;
	area = 0;
	existence = -1;
	type = -1;
}
Triangle::Triangle(double _a, double _b, double _c)
{
	a = _a;
	b = _b;
	c = _c;
	if (a == 0.0 || b == 0.0 || c == 0.0)
		existence = -1; // треугольник не задан
	if (a + b > c && b + c > a && a + c > b)
		existence = 1; // треугольник существует
	else
		existence = 0; // треугольник не существует
	if (existence == 1)
	{
		if (c*c == a * a + b * b)
			type = 0; // прямоугольный
		if (c*c > a * a + b * b)
			type = 1; // тупоугольный
		if (c*c < a * a + b * b)
			type = 2; // остроугольный
		area = sqrt((0.5 * (a + b + c))*(0.5 * (a + b + c) - a)*(0.5 * (a + b + c) - b)*(0.5 * (a + b + c) - c));
		perimeter = a + b + c;
	}
	else
	{
		type = -1;
		area = 0;
		perimeter = 0;
	}
}
Triangle::~Triangle()
{
	a = 0.0;
	b = 0.0;
	c = 0.0;
	perimeter = 0;
	area = 0;
	existence = -1;
	type = -1;
}
int main()
{
	Triangle triangle(3.0, 4.0, 5.0);
	cout << triangle.existence << "\n";
	cout << triangle.area << "\n";
	cout << triangle.perimeter << "\n";
	getchar();
	getchar();
	return 0;
}