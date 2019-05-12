#include "ProcCenter.h";

void ProcCenter::CreditPay(int _pay, int _index)
{
	balance[_index] += pay[_index];
	balance[_index] -= _pay;
	--remainingPayments[_index];
	creditSumm[_index] -= _pay;
}
ProcCenter::ProcCenter()
{
	size = 0;
	client = NULL;
	fullName = NULL;
	balance = NULL;
	creditType = NULL;
	remainingPayments = NULL;
	creditSumm = NULL;
	password = NULL;
	pay = NULL;
}
ProcCenter::ProcCenter(string path)
{
	ifstream file;
	file.open(path);
	file >> *this;
	file.close();
}
ProcCenter::~ProcCenter()
{
	delete[] client;
	delete[] fullName;
	delete[] balance;
	delete[] creditType;
	delete[] remainingPayments;
	delete[] creditSumm;
	delete[] password;
	delete[] pay;
}
int ProcCenter::Autorization(string _client, string _password)
{
	int index = -1;
	for (int i = 0; i < size; ++i)
		if (client[i] == _client && password[i] == _password)
		{
			index = i;
			break;
		}
	return index;
}
void ProcCenter::GetCredit(int _creditType, int _creditSumm, int _remainingPayments, int _summ, int _index)
{
	balance[_index] += _summ;
	creditType[_index] = _creditType;
	creditSumm[_index] = _creditSumm;
	remainingPayments[_index] = _remainingPayments;
}
ostream& operator<< (ostream& stream, const ProcCenter& prc)
{
	stream << prc.size;
	for (int i = 0; i < prc.size; ++i)
		stream << '\n' << prc.client[i] << ' ' << prc.fullName[i] << ' ' << prc.balance[i] << ' ' << prc.creditType[i] << ' ' << prc.remainingPayments[i] << ' ' << prc.creditSumm[i] << ' ' << prc.password[i] << ' ' << prc.pay[i];
	stream << endl;
	return stream;
}
istream& operator>> (istream& stream, ProcCenter& prc)
{
	stream >> prc.size;
	prc.client = new string[prc.size];
	prc.fullName = new string[prc.size];
	prc.balance = new int[prc.size];
	prc.creditType = new int[prc.size];
	prc.remainingPayments = new int[prc.size];
	prc.creditSumm = new int[prc.size];
	prc.password = new string[prc.size];
	prc.pay = new int[prc.size];
	string t1, t2, t3;
	for (int i = 0; i < prc.size; ++i)
	{
		stream >> prc.client[i] >> t1 >> t2 >> t3 >> prc.balance[i] >> prc.creditType[i] >> prc.remainingPayments[i] >> prc.creditSumm[i] >> prc.password[i] >> prc.pay[i];
		prc.fullName[i] = t1 + ' ' + t2 + ' ' + t3;
	}
	return stream;
}