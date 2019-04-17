#pragma once
using namespace std;
#include "Event.h";
#include <vector>

class Pedometer
{
private:
	vector<Event> events;
	int eventsCount;
public:
	Pedometer();
	Pedometer(int event_count);
	Pedometer(string path);

	string MaxStepsPerMonth(int _month, int _year); // максимальное число шагов в день за месяц
	string MaxStepsAllTime(); // максимальное число шагов в день все время
	int AverageStepsPerMonth(int _month, int _year); // среднее число шагов в день в определенном месяце
	int AverageStepsAllTime(); // среднее число шагов в день за все время
	void AddEvent(string p0, int p1, int p2, int p3, int p4, int p5); // добавить подсчет
	string FindEvents(string p0, int p1, int p2);
	friend ostream& operator<< (ostream& stream, const Pedometer& ped); // вывод
	friend istream& operator>> (istream& stream, Pedometer& ped); // ввод

	~Pedometer();
};