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
	Dictionary dict;
	while (true)
	{
		try
		{
			int menu = 0;
			clear();
			cout << "Выберите пункт меню:\n";
			cout << "1. Узнать перевод слова\n";
			cout << "2. Узнать, есть ли слово в словаре\n";
			cout << "3. Добавить слово и его перевод в словарь\n";
			cout << "4. Изменить перевод слова\n";
			cout << "5. Узнать число слов в словаре\n";
			cout << "6. Показать словарь\n";
			cout << "7. Удалить слово\n";
			cout << "8. Сохранить словарь в файл\n";
			cout << "9. Загрузить словарь из файла\n";
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
				switch (menu)
				{
				case 0:
					return 0;
				case 1:
					cout << "Введите слово: ";
					cin >> temp;
					cout << "Перевод: " << dict.Translation(temp) << endl;
					break;
				case 2:
					cout << "Введите слово: ";
					cin >> temp;
					if (dict.Find(temp) == -1)
						cout << "Слова \"" << temp << "\" нет в словаре." << endl;
					else
						cout << "Слово \"" << temp << "\" имеется в словаре." << endl;
					break;
				case 3:
					cout << "Введите слово: ";
					cin >> temp;
					cout << "Введите его перевод: ";
					cin >> temp1;
					dict.Add(temp, temp1);
					cout << '\n' << temp << " = " << temp1 << " добавлено в словарь." << endl;
					break;
				case 4:
					cout << "Введите слово: ";
					cin >> temp;
					cout << "Введите перевод: ";
					cin >> temp1;
					dict.Change(temp, temp1);
					cout << "Перевод слова \"" << temp << "\" изменён" << endl;
					break;
				case 5:
					cout << "Число слов в словаре: " << dict.Size() << endl;
					break;
				case 6:
					cout << dict << endl;
					break;
				case 7:
					cout << "Введите слово: ";
					cin >> temp;
					dict.Delete(temp);
					cout << "Слово \"" << temp << "\" удалено" << endl;
					break;
				case 8:
					cout << "Введите название файла (без расширения): ";
					cin >> temp;
					ofile.open(temp + ".txt");
					ofile << dict;
					ofile.close();
					break;
				case 9:
					cout << "Введите название файла (с расширением): ";
					cin >> temp;
					ifile.open(temp);
					dict >> ifile;
					ifile.close();
					break;
				default:
					break;
				}
				cout << "Для продолжения нажмите любую клавишу..." << endl;
				_getch();
			}

		}
		catch (TDictException ex)
		{
			if (ex.extype == dictWORDNOTFOUND)
			{
				cout << "Запрошен перевод отсутствующегося в словаре слова. Слово: " << ex.word << endl;
				cout << "Для продолжения нажмите любую клавишу..." << endl;
				_getch();
			}
			if (ex.extype == dictOUTOFRANGE)
			{
				cout << "Выход за пределы словаря. Индекс: " << ex.bspos << endl;
				cout << "Для продолжения нажмите любую клавишу..." << endl;
				_getch();
			}
		}
	}
}