#pragma once
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
#include "ProcCenter.h"


class Credit
{
private:
	ProcCenter *prc;
	int user = -1; // индекс из ProcCenter, -1 если не авторизован
public:
	Credit() { prc = NULL; };
	Credit(string path) { prc = new ProcCenter(path); };

	~Credit() { delete prc; };

	string GetFullName() { return prc->GetFullName(user); };
	string GetClient() { return prc->GetClient(user); };
	int GetBalance() { return prc->GetBalance(user); };
	int GetPay() { return prc->GetPay(user); };
	int GetCreditType() { return prc->GetCreditType(user); };
	int GetRemainingPayments() { return prc->GetRemainingPayments(user); };
	int GetCreditSumm() { return prc->GetCreditSumm(user); };
	string AvailableCredits(); // какие кредиты возможно получить данному пользователю
	bool GetCredit(int type, int summ); // получить кредит
	bool ActiveCredit(); // есть ли кредит
	void CreditPay(int pay); // оплата кредита
	bool PossibilityGetCredit(int type, int summ); // возможно ли получить определенный кредит
	int Autorization(string _client, string _password);
	bool Autorized(); // авторизирован или нет
	void Logout(); // выход из личного кабинета
};