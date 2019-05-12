#include "Credit.h";

bool Credit::ActiveCredit()
{
	if (prc->GetCreditType(user) == 0)
		return false;
	return true;
}
void Credit::CreditPay(int pay)
{
	prc->CreditPay(pay, user);
}
bool Credit::PossibilityGetCredit(int type, int summ)
{
	int balance = prc->GetBalance(user);
	int pay = prc->GetPay(user);
	switch (type)
	{
	case 1:
		if (summ >= 100000 && summ < 1000000 && summ * 1.08 <= balance + pay * 12 && summ * 1.08 / 12 * 6 <= balance)
			return true;
		break;
	case 2:
		if (summ >= 100000 && summ < 1000000 && summ * 1.5 <= balance + pay * 12 * 5 && summ * 1.5 / 12 * 6 <= balance)
			return true;
		break;
	case 3:
		if (summ >= 1000000 && summ <= 3000000 && summ * 1.12 <= balance + pay * 12 && summ * 1.12 / 12 * 6 <= balance)
			return true;
		break;
	case 4:
		if (summ >= 1000000 && summ <= 3000000 && summ * 1.7 <= balance + pay * 12 * 5 && summ * 1.7 / 12 * 6 <= balance)
			return true;
		break;
	default:
		break;
	}
	return false;
}

bool Credit::GetCredit(int type, int summ)
{

	if (!ActiveCredit() && PossibilityGetCredit(type, summ))
	{
		int balance = prc->GetBalance(user);
		int pay = prc->GetPay(user);
		switch (type)
		{
		case 1:
			prc->GetCredit(type, summ * 1.08, 12, summ, user);
			break;
		case 2:
			prc->GetCredit(type, summ * 1.5, 60, summ, user);
			break;
		case 3:
			prc->GetCredit(type, summ * 1.12, 12, summ, user);
			break;
		case 4:
			prc->GetCredit(type, summ * 1.7, 60, summ, user);
			break;
		default:
			break;
		}
		return true;
	}
	else
		return false;
}
string Credit::AvailableCredits()
{
	if (!ActiveCredit())
	{
		string result = "";
		int count = 1;
		int balance = prc->GetBalance(user); // 1 до 1 млн 8%    1  1..3 12%
		int pay = prc->GetPay(user);         // 5 до 1 млн 10%   5  1..3 14%
		if (100000 * 1.08 <= balance + pay * 12 && 100000 * 1.08 / 12 * 6 <= balance)
		{
			result += to_string(count) + ". От 100 тысяч до 1 миллиона на один год под 8% годовых.\n";
			++count;
		}
		if (100000 * 1.5 <= balance + pay * 12 * 5 && 100000 * 1.5 / 60 * 6 <= balance)
		{
			result += to_string(count) + ". От 100 тысяч до 1 миллиона на 5 лет под 10% годовых.\n";
			++count;
		}
		if (1000000 * 1.12 <= balance + pay * 12 && 100000 * 1.12 / 12 * 6 <= balance)
		{
			result += to_string(count) + ". От 1 млн до 3 млн на один год под 12% годовых.\n";
			++count;
		}
		if (1000000 * 1.7 <= balance + pay * 12 * 5 && 1000000 * 1.7 / 60 * 6 <= balance)
		{
			result += to_string(count) + ". От 1 млн до 3 млн на 5 лет под 14% годовых.\n";
			++count;
		}
		if (count == 1)
			result = "Вы не можете получить кредит!";
		return result;
	}
	else
	{
		return "Вы не можете получить кредит, пока не погасите текущий!";
	}
}
void Credit::Logout()
{
	user = -1;
	ofstream ofile;
	ofile.open("procCenter.txt");
	ofile << *prc;
	ofile.close();
};

int Credit::Autorization(string _client, string _password)
{
	user = prc->Autorization(_client, _password);
	return user;
};
bool Credit::Autorized()
{
	if (user == -1)
		return false;
	return true;
}
