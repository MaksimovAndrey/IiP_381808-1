using namespace std;
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <math.h>
#include "Vector.h"

Vector::Vector(const Vector&vec)
{
	size = vec.size;
	components = new int[size];
	for (int i = 0; i < size; ++i)
	{
		if (vec.components[i] == NULL)
			throw TVectorException(vectorCOMPNULLVALUE, i);
		else
			components[i] = vec.components[i];
	}
}
Vector::Vector(string path)
{
	ifstream file;
	file.open(path);
	int _size;
	file >> _size;
	if (_size > 0 && _size < 21)
	{
		size = _size;
		components = new int[size];
		for (int i = 0; i < size; ++i)
			components[i] = NULL;
		for (int i = 0; i < size; ++i)
		{
			file >> components[i];
			if (components[i] == NULL)
			{
				file.close();
				throw TVectorException(vectorFILEREADEX, i);
			}
		}
		file.close();
	}
	else
	{
		file.close();
		throw TVectorException(vectorOUTOFSIZE, _size);
	}
}
Vector::Vector(int _size)
{
	if (_size > 20)
		throw TVectorException(vectorOUTOFSIZE, _size);
	else
	{
		size = _size;
		components = new int[size];
		for (int i = 0; i < size; ++i)
			components[i] = NULL;
	}
}
Vector::Vector(int _size, int c1)
{
	if (_size != 1)
		throw TVectorException(vectorINICOUTOFSIZE, _size);
	else
	{
		size = _size;
		components = new int[size];
		components[0] = c1;
	}
}
Vector::Vector(int _size, int c1, int c2)
{
	if (_size != 2)
		throw TVectorException(vectorINICOUTOFSIZE, _size);
	else
	{
		size = _size;
		components = new int[size];
		components[0] = c1;
		components[1] = c2;
	}
}
Vector::Vector(int _size, int c1, int c2, int c3)
{
	if (_size != 3)
		throw TVectorException(vectorINICOUTOFSIZE, _size);
	else
	{
		size = _size;
		components = new int[size];
		components[0] = c1;
		components[1] = c2;
		components[2] = c3;
	}
}
Vector::~Vector()
{
	size = 0;
	delete[] components;
}
void Vector::setSize(int _size)
{
	if (_size > 20 || _size < 0)
		throw TVectorException(vectorOUTOFSIZE, _size);
	else
	{
		size = _size;
		delete[] components;
		components = new int[size];
		for (int i = 0; i < size; ++i)
			components[i] = NULL;
	}
};
string Vector::getFile(string name)
{
	ofstream file;
	name += ".txt";
	file.open(name);
	file << size;
	for (int i = 0; i < size; ++i)
		file << '\n' << components[i];
	file.close();
	return name;
}
double Vector::length()
{
	double result = 0;
	for (int i = 0; i < size; ++i)
	{
		if (components[i] != NULL)
			result += components[i] * components[i];
		else
			throw TVectorException(vectorCOMPNULLVALUE, i);
	}
	return sqrt(result);
}
int& Vector::operator[] (int index)
{
	if (index < 0 || index >= size)
		throw TVectorException(vectorOUTOFRANGE, index);
	return components[index];
}
const int& Vector::operator[] (int index) const
{
	if (index < 0 || index >= size)
		throw TVectorException(vectorOUTOFRANGE, index);
	return components[index];
}
Vector& Vector::operator= (const Vector& vec)
{
	if (this != &vec)
	{
		delete[] components;
		size = vec.size;
		components = new int[size];
		for (int i = 0; i < size; ++i)
			(*this)[i] = vec.components[i];
	}
	return *this;
}int Vector::operator* (const Vector& vec)
{
	if (size == vec.size)
	{
		int result = 0;
		for (int i = 0; i < size; ++i)
		{
			if (components[i] != NULL && vec.components[i] != NULL)
				result += components[i] * vec.components[i];
			else
				throw TVectorException(vectorCOMPNULLVALUE, i);
		}
		return result;
	}
	else
		throw TVectorException(vectorOUTOFSIZE, size);
}
Vector Vector::operator+ (const Vector& vec)
{
	if (size == vec.size)
	{
		Vector result(size);
		for (int i = 0; i < size; ++i)
		{
			if (components[i] != NULL && vec.components[i] != NULL)
				result.components[i] = components[i] + vec.components[i];
			else
				throw TVectorException(vectorCOMPNULLVALUE, i);
		}
		return result;
	}
	else
		throw TVectorException(vectorOUTOFSIZE, size);
}
Vector Vector::operator+= (const Vector& vec)
{
	if (size == vec.size)
	{
		for (int i = 0; i < size; ++i)
		{
			if (components[i] != NULL && vec.components[i] != NULL)
				components[i] += vec.components[i];
			else
				throw TVectorException(vectorCOMPNULLVALUE, i);
		}
		return *this;
	}
	else
		throw TVectorException(vectorOUTOFSIZE, size);
}
ostream& operator<< (ostream& stream, const Vector& vec)
{
	stream << vec.size << '\n' << vec.components[0];
	for (int i = 1; i < vec.size; ++i)
		stream << ' ' << vec.components[i];
	stream << endl;
	return stream;
}
istream& operator>> (istream& stream, Vector& vec)
{
	int tmp;
	stream >> tmp;
	if (tmp < 0 || tmp > 20)
		throw TVectorException(vectorOUTOFSIZE, tmp);
	else
	{
		vec.size = tmp;
		vec.components = new int[tmp];
		for (int i = 0; i < vec.size; ++i)
			stream >> vec.components[i];
		return stream;
	}
}
