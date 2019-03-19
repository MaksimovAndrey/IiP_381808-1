#include <iostream>
#include <stdio.h>
#include <fstream>
#include <locale.h>
#include <string>
#include <math.h>
#include "Vector.h"
int main()
{
	setlocale(LC_CTYPE, "Russian");
	try
	{
		Vector vector1, vector2;
		int tmp, tmp1;
		string tmpstr;
		cout << "Введите размер вектора 1. Затем его компоненты\n";
		cin >> vector1;
		cout << "Введите размер вектора 2. Затем его компоненты\n";
		cin >> vector2;
		cout << "Сумма векторов: " << vector1 + vector2;
		cout << "\nСкалярное произведение векторов: " << vector1 * vector2;
		cout << "\nДлина первого вектора: " << vector1.length();
		vector1 = vector2;
		cout << "\nВектор1 = Вектор2. Вектор 1: " << vector1;
		cout << "\nУстановить размер вектора: ";
		cin >> tmp;
		vector1.setSize(tmp);
		cout << "\nПолучение размера вектора: " << vector1.getSize();
		cout << "\nУстановить компоненту вектора (индекс и число): ";
		cin >> tmp >> tmp1;
		vector1[tmp] = tmp1;
		cout << "\nИндексация. Компонента " << tmp << " = " << vector1[tmp];
		cout << "\nСохранение вектора в файл. Название файла: ";
		cin >> tmpstr;
		cout << "Сохранение вектора в файл. Название выходного файла: " << vector1.getFile(tmpstr);
		cout << "\nВведите путь файла с вектором (вместо \ - \\ или /): ";
		cin >> tmpstr;
		Vector vector3(tmpstr);
		cout << "\nЧтение вектора из файла: " << vector3;
		cout << "\nНажмите любую клавишу, чтобы завершить работу...";
	}
	catch (TVectorException ex)
	{
		if (ex.extype == vectorOUTOFSIZE)
		{
			cout << "Превышен допустимый размер вектора или размеры векторов не совпадают. Размер: " << ex.bspos << endl;
		}
		if (ex.extype == vectorOUTOFRANGE)
		{
			cout << "Выход за пределы массива компонент вектора. Индекс: " << ex.bspos << endl;
		}
		if (ex.extype == vectorCOMPNULLVALUE)
		{
			cout << "Компонента вектора не задана. Индекс компоненты: " << ex.bspos << endl;
		}
		if (ex.extype == vectorINICOUTOFSIZE)
		{
			cout << "При инициализации вектора превышен допустимый размер вектора. Размер: " << ex.bspos << endl;
		}
		if (ex.extype == vectorFILEREADEX)
		{
			cout << "При чтении файла произошла ошибка. Компонента не найдена. Индекс компоненты: " << ex.bspos << endl;
		}
		cout << "\nНажмите любую клавишу, чтобы завершить работу...";
	}
	getchar();
	getchar();
}