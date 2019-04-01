using namespace std;
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <locale.h>
#include <string>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include "Dictionary.h"

Dictionary::Dictionary()
{
	dict = new string*[2];
	for (int i = 0; i < 2; ++i)
		dict[i] = new string[1000];
}
Dictionary::Dictionary(const Dictionary& d)
{
	dict = new string*[2];
	for (int i = 0; i < 2; ++i)
		dict[i] = new string[1000];
	size = d.size;
	for (int i = 0; i < d.size; ++i)
	{
		dict[0][i] = d.dict[0][i];
		dict[1][i] = d.dict[1][i];
	}
}
Dictionary::Dictionary(int _size, string t[])
{
	dict = new string*[2];
	for (int i = 0; i < 2; ++i)
		dict[i] = new string[1000];
	size = _size;
	for (int i = 0; i < size; ++i)
	{
		dict[0][i] = t[i * 2];
		dict[1][i] = t[i * 2 + 1];
	}
}
Dictionary::Dictionary(string path)
{
	dict = new string*[2];
	for (int i = 0; i < 2; ++i)
		dict[i] = new string[1000];
	ifstream file;
	file.open(path);
	*this >> file;
}
Dictionary::~Dictionary()
{
	for (int i = 0; i < 2; ++i)
		delete[] dict[i];
	delete[] dict;
}

void Dictionary::Add(string w1, string w2)
{
	dict[0][size] = w1;
	dict[1][size] = w2;
	++size;
	return;
}
int Dictionary::Find(string word)
{
	for (int i = 0; i < size; ++i)
	{
		if (dict[0][i] == word)
			return i;
		if (dict[1][i] == word)
			return i + 1000;
	}
	return -1;
}
string Dictionary::Translation(string word)
{
	int tmp = Find(word);
	if (tmp != -1)
	{
		if (tmp >= 1000)
			return dict[0][tmp - 1000];
		else
			return dict[1][tmp];
	}
	else
		throw TDictException(dictWORDNOTFOUND, 0, word);
}
void Dictionary::Change(string word, string t)
{
	int tmp = Find(word);
	if (tmp == -1)
		throw TDictException(dictWORDNOTFOUND, 0, word);
	else
	{
		if (tmp >= 1000)
			dict[0][tmp - 1000] = t;
		else
			dict[1][tmp] = t;
		return;
	}
}
void Dictionary::Delete(string word)
{
	int tmp = Find(word);
	if (tmp == -1)
		throw TDictException(dictWORDNOTFOUND, 0, word);
	else
	{
		if (tmp >= 1000)
			tmp -= 1000;
		for (int i = tmp; i < size - 1; ++i)
		{
			dict[0][i] = dict[0][i + 1];
			dict[1][i] = dict[1][i + 1];
		}
		--size;
		return;
	}
}
Dictionary& Dictionary::operator= (const Dictionary& d)
{
	size = d.size;
	for (int i = 0; i < size; ++i)
	{
		dict[0][i] = d.dict[0][i];
		dict[1][i] = d.dict[1][i];
	}
	return *this;
}
Dictionary Dictionary::operator+ (const Dictionary& d)
{
	Dictionary tmp;
	tmp = *this;
	tmp += d;
	return tmp;
}
Dictionary Dictionary::operator+= (const Dictionary& d)
{
	if (size == 0)
	{
		*this = d;
	}
	else
	{
		int j;
		for (int i = 0; i < d.size; ++i)
		{
			for (j = 0; j < size; ++j)
			{
				if (d.dict[0][i] == dict[0][j])
				{
					j = -1;
					break;
				}
			}
			if (j != -1)
			{

				dict[0][size] = d.dict[0][i];
				dict[1][size] = d.dict[1][i];
				++size;
			}
		}
	}
	return *this;
}

string& Dictionary::operator[] (int index)
{
	if (index < 0 || index >= size)
		throw TDictException(dictOUTOFRANGE, index, "");
	return dict[1][index];
}
const string& Dictionary::operator[] (int index) const
{
	if (index < 0 || index >= size)
		throw TDictException(dictOUTOFRANGE, index, "");
	return dict[1][index];
}
string& Dictionary::operator[] (string word)
{
	int tmp = Find(word);
	if (tmp >= 1000)
		return dict[0][tmp - 1000];
	else
		return dict[1][tmp];
}
const string& Dictionary::operator[] (string word) const
{
	int tmp = -1;
	for (int i = 0; i < size; ++i)
	{
		if (dict[0][i] == word)
		{
			tmp = i;
			break;
		}
		if (dict[1][i] == word)
		{
			tmp = i + 1000;
			break;
		}
	}
	if (tmp != -1)
	{
		if (tmp >= 1000)
			return dict[0][tmp - 1000];
		else
			return dict[1][tmp];
	}
	else
	{
		throw TDictException(dictWORDNOTFOUND, -1, word);
	}
}
ostream& operator<< (ostream& stream, const Dictionary& dict)
{
	stream << dict.size;
	for (int i = 0; i < dict.size; ++i)
		stream << '\n' << dict.dict[0][i] << ' ' << dict.dict[1][i];
	stream << endl;
	return stream;
}
istream& operator>> (istream& stream, Dictionary& dict)
{
	stream >> dict.size;
	for (int i = 0; i < dict.size; ++i)
		stream >> dict.dict[0][i] >> dict.dict[1][i];
	return stream;
}
ifstream& operator>> (Dictionary& dict, ifstream& fstream)
{
	fstream >> dict.size;
	for (int i = 0; i < dict.size; ++i)
		fstream >> dict.dict[0][i] >> dict.dict[1][i];
	return fstream;
}