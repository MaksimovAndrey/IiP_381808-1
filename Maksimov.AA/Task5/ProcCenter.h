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


class ProcCenter
{
private:
	int size;
	string *client;
	string *fullName;
	int *balance;
	int *creditType;
	int *remainingPayments;
	int *creditSumm;
	string *password;
	int *pay;
public:
	ProcCenter();
	ProcCenter(string path);

	string GetFullName(int _index) { return fullName[_index]; };
	string GetClient(int _index) { return client[_index]; };
	int GetBalance(int _index) { return balance[_index]; };
	int GetCreditType(int _index) { return creditType[_index]; };
	int GetRemainingPayments(int _index) { return remainingPayments[_index]; };
	int GetCreditSumm(int _index) { return creditSumm[_index]; };
	int GetPay(int _index) { return pay[_index]; };
	void CreditPay(int pay, int _index);
	int Autorization(string _client, string _password);
	void GetCredit(int _creditType, int _creditSumm, int _remainingPayments, int _summ, int _index);

	friend ostream& operator<< (ostream& stream, const ProcCenter& prc); // вывод
	friend istream& operator>> (istream& stream, ProcCenter& prc); // ввод

	~ProcCenter();
};