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
	int Existence(); // существование
	double Perimeter(); // периметр
	double Area(); // площадь
	int Type(); // тип
	Triangle();
	~Triangle();
};
Triangle::Triangle()
{
	a = 0.0;
	b = 0.0;
	c = 0.0;
}
int Triangle::Type()
{
	if (c*c == a * a + b * b)
		type = 0; // прямоугольный
	if (c*c > a * a + b * b)
		type = 1; // тупоугольный
	if (c*c < a * a + b * b)
		type = 1; // остроугольный
	return type;
}
double Triangle::Perimeter()
{
	perimeter = a + b + c;
	return perimeter;
}
double Triangle::Area()
{
	area = sqrt((0.5 * (a + b + c))*(0.5 * (a + b + c) - a)*(0.5 * (a + b + c) - b)*(0.5 * (a + b + c) - c));
	return area;
}
Triangle::Triangle(double _a, double _b, double _c)
{
	a = _a;
	b = _b;
	c = _c;
}
int Triangle::Existence()
{
	if (a == 0.0 || b == 0.0 || c == 0.0)
	{
		existence = -1; // треугольник не задан
		return -1;
	}
	if (a + b > c && b + c > a && a + c > b)
	{
		existence = 1; // треугольник существует
		return 1;
	}
	else
	{
		existence = 0; // треугольник не существует
		return 0;
	}
}
Triangle::~Triangle()
{
	a = 0.0;
	b = 0.0;
	c = 0.0;
}
int main()
{
	Triangle triangle(3.0, 4.0, 5.0);
	cout << triangle.Existence() << "\n";
	cout << triangle.existence << "\n";
	cout << triangle.Area() << "\n";
	cout << triangle.area << "\n";
	cout << triangle.Perimeter() << "\n";
	getchar();
	getchar();
	return 0;
}