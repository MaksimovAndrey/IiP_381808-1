using namespace std;
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <locale.h>
#include <string>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include "Pedometer.h"

void clear() // очистить консоль
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Pedometer ped("test.txt");
	while (true)
	{
		int menu = 0;
		clear();
		cout << "Выберите пункт меню:\n";
		cout << "1. Задать подсчеты\n";
		cout << "2. Добавить подсчет\n";
		cout << "3. Максимальное число шагов в определенном месяце\n";
		cout << "4. Максимальное число шагов за все время\n";
		cout << "5. Среднее число шагов в определенном месяце\n";
		cout << "6. Среднее число шагов за все время\n";
		cout << "7. Получить информацию о подсчете, выбранном по дате и интервалу времени\n";
		cout << "8. Сохранить в файл\n";
		cout << "9. Загрузить из файла\n";
		cout << "0. Завершить работу\n";
		cout << "Ввод: ";

		cin >> menu;
		if (!cin)
		{
			cout << "Введите цифру!\n";
			cout << "Для продолжения нажмите любую клавишу..." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			_getch();
		}
		else
		{
			string temp, temp1;
			ofstream ofile;
			ifstream ifile;
			string p0;
			int p1, p2, p3, p4, p5;
			switch (menu)
			{
			case 0:
				return 0;
			case 1:
				cout << "Введите количество подсчетов: ";
				cin >> ped;
				break;
			case 2:
				cout << "Введите дату (11.09.1996): ";
				cin >> p0;
				cout << "Введите час начала: ";
				cin >> p1;
				cout << "Введите минуту начала: ";
				cin >> p2;
				cout << "Введите час конца: ";
				cin >> p3;
				cout << "Введите минуту конца: ";
				cin >> p4;
				cout << "Введите количество шагов: ";
				cin >> p5;
				ped.AddEvent(p0, p1, p2, p3, p4, p5);
				break;
			case 3:
				cout << "Введите год: ";
				cin >> p1;
				cout << "Введите месяц: ";
				cin >> p2;
				cout << ped.MaxStepsPerMonth(p2, p1) << endl;
				break;
			case 4:
				cout << ped.MaxStepsAllTime() << endl;
				break;
			case 5:
				cout << "Введите год: ";
				cin >> p1;
				cout << "Введите месяц: ";
				cin >> p2;
				cout << ped.AverageStepsPerMonth(p2, p1) << endl;
				break;
			case 6:
				cout << ped.AverageStepsAllTime() << endl;
				break;
			case 7:
				cout << "Введите дату (29.11.2000): ";
				cin >> p0;
				cout << "Введите час начала: ";
				cin >> p1;
				cout << "Введите минуту начала: ";
				cin >> p2;
				cout << "Введите час конца: ";
				cin >> p3;
				cout << "Введите минуту конца: ";
				cin >> p4;
				cout << ped.FindEvents(p0, p1 * 60 + p2, p3 * 60 + p4) << endl;
				break;
			case 8:
				cout << "Введите название файла (без расширения): ";
				cin >> temp;
				ofile.open(temp + ".txt");
				ofile << ped;
				ofile.close();
				break;
			case 9:
				cout << "Введите название файла (с расширением): ";
				cin >> temp;
				ifile.open(temp);
				ifile >> ped;
				ifile.close();
				break;
			default:
				break;
			}
			cout << "Для продолжения нажмите любую клавишу..." << endl;
			_getch();
		}
	}
}