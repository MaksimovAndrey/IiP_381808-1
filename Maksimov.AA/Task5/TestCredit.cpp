using namespace std;
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <locale.h>
#include <string>
#include <math.h>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include "Credit.h"

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
	Credit cr("procCenter.txt");
	while (true)
	{
		int menu = 0;
		while (!cr.Autorized())
		{
			clear();
			string login, pass;
			cout << "Авторизация\n";
			cout << "Введите номер счета: ";
			cin >> login;
			if (login.length() == 4)
			{
				cout << "Введите пароль: ";
				cin >> pass;
				if (cr.Autorization(login, pass) != -1)
					continue;
				else
					cout << "Неверный номер или пароль!\n";
			}
			else
				cout << "Неверный формат номера счета\n";
			cout << "Для продолжения нажмите любую клавишу..." << endl;
			_getch();
		}
		clear();
		cout << "Здравствуйте, " << cr.GetFullName() << "!\n\n";
		cout << "Выберите пункт меню:\n";
		cout << "1. Информация\n";
		cout << "2. Кредитование\n";
		cout << "0. Выход\n";
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
			switch (menu)
			{
			case 0:
				cr.Logout();
				break;
			case 1:
				cout << "Информация о счёте " << cr.GetClient() << ":\n";
				cout << "ФИО: " << cr.GetFullName() << '\n';
				cout << "Баланс: " << cr.GetBalance() << '\n';
				cout << "Заработная плата: " << cr.GetPay() << '\n';
				cout << "Тип кредита: " << cr.GetCreditType() << '\n';
				cout << "Остаток по кредиту: " << cr.GetCreditSumm() << '\n';
				cout << "Осталось выплат: " << cr.GetRemainingPayments() << '\n';
				break;
			case 2:
				while (true)
				{
					int menu1 = 0;
					clear();
					cout << "Здравствуйте, " << cr.GetFullName() << "!\n\n";
					cout << "Выберите пункт меню:\n";
					cout << "1. Возможные кредиты\n";
					cout << "2. Состояние кредита\n";
					cout << "3. Оплата кредита\n";
					cout << "4. Взять кредит\n";
					cout << "0. Назад\n";
					cout << "Ввод: ";
					cin >> menu1;
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
						int payment;
						int type;
						int summ;
						switch (menu1)
						{
						case 0:
							break;
						case 1:
							cout << cr.AvailableCredits();
							break;
						case 2:
							if (cr.ActiveCredit())
							{
								cout << "Осталось выплатить " << cr.GetCreditSumm() << '\n';
								cout << "Осталось " << cr.GetRemainingPayments() << " месяцев\n";
							}
							else
								cout << "Нет активного кредита\n";
							break;
						case 3:
							cout << "Введите сумму выплаты (минимум " << cr.GetCreditSumm() / cr.GetRemainingPayments() << "): ";
							cin >> payment;
							if (payment >= cr.GetCreditSumm() / cr.GetRemainingPayments() && payment <= cr.GetBalance())
								cr.CreditPay(payment);
							else
								cout << "Неверная сумма платежа!\n";
							break;
						case 4:
							cout << "1. От 100 тысяч до 1 миллиона на один год под 8% годовых.\n";
							cout << "2. От 100 тысяч до 1 миллиона на 5 лет под 10% годовых.\n";
							cout << "3. От 1 млн до 3 млн на один год под 12% годовых.\n";
							cout << "4. От 1 млн до 3 млн на 5 лет под 14% годовых.\n";
							cout << "Ввод: ";
							cin >> type;
							cout << "Введите сумму кредита: ";
							cin >> summ;
							if (cr.GetCredit(type, summ))
								cout << "Успех!\n";
							else
								cout << "Ошибка!\n";
							break;
						default:
							break;
						}
						cout << "Для продолжения нажмите любую клавишу..." << endl;
						_getch();
						if (menu1 == 0)
							break;
					}
				}
				break;
			default:
				break;
			}
			cout << "Для продолжения нажмите любую клавишу..." << endl;
			_getch();
		}
	}
}