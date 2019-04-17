#include <iostream>
#include <stdio.h>
#include <fstream>
#include <locale.h>
#include <string>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "Pedometer.h"


string Pedometer::MaxStepsPerMonth(int _month, int _year)
{
	int max = 0;
	string date = "";
	string temp_date;
	for (int i = 1; i < 32; ++i)
	{
		int temp_max = 0;
		for (int j = 0; j < eventsCount; ++j)
			if (_month == events[j].month && _year == events[j].year && i == events[j].day)
			{
				temp_max += events[j].count;
				temp_date = events[j].GetDate();
			}
		if (max < temp_max)
		{
			max = temp_max;
			date = temp_date;
		}
	}
	return to_string(max) + ' ' + date;
}
string Pedometer::MaxStepsAllTime()
{
	int max = 0;
	int temp_max;
	string date = "";
	int *years = new int[50];
	int yearsCount = 0;
	for (int i = 0; i < eventsCount; ++i)
	{
		int j;
		for (j = 0; j < yearsCount; ++j)
			if (events[i].year == years[j])
			{
				j = yearsCount + 1;
				break;
			}
		if (j != yearsCount + 1)
		{
			years[yearsCount] = events[i].year;
			++yearsCount;
		}
	}
	for (int i = 0; i < yearsCount; ++i)
		for (int j = 1; j <= 12; ++j)
		{
			string temp_date;
			for (int i1 = 1; i1 < 32; ++i1)
			{
				int temp_max = 0;
				for (int j1 = 0; j1 < eventsCount; ++j1)
					if (j == events[j1].month && years[i] == events[j1].year && i1 == events[j1].day)
					{
						temp_max += events[j1].count;
						temp_date = events[j1].GetDate();
					}
				if (max < temp_max)
				{
					max = temp_max;
					date = temp_date;
				}
			}
		}
	delete[] years;
	return to_string(max) + " " + date;
}
int Pedometer::AverageStepsPerMonth(int _month, int _year)
{
	int steps = 0;
	int days = 0;
	for (int i = 1; i < 32; ++i)
	{
		int _day = 0;
		for (int j = 0; j < eventsCount; ++j)
			if (_month == events[j].month && _year == events[j].year && i == events[j].day)
				_day += events[j].count;
		if (_day != 0)
		{
			++days;
			steps += _day;
		}
	}
	if (days != 0)
		return steps / days;
	else
		return 0;
}
int Pedometer::AverageStepsAllTime()
{
	int months = 0;
	int steps = 0;
	int *years = new int[50];
	int yearsCount = 0;
	for (int i = 0; i < eventsCount; ++i)
	{
		int j;
		for (j = 0; j < yearsCount; ++j)
			if (events[i].year == years[j])
			{
				j = yearsCount + 1;
				break;
			}
		if (j != yearsCount + 1)
		{
			years[yearsCount] = events[i].year;
			++yearsCount;
		}
	}
	for (int i = 0; i < yearsCount; ++i)
		for (int j = 1; j <= 12; ++j)
		{
			int temp_steps = AverageStepsPerMonth(j, years[i]);
			if (temp_steps != 0)
			{
				++months;
				steps += temp_steps;
			}
		}
	delete[] years;
	if (months != 0)
		return steps / months;
	else
		return 0;
}
void Pedometer::AddEvent(string p0, int p1, int p2, int p3, int p4, int p5)
{
	Event temp;
	temp.Inic(p0, p1, p2, p3, p4, p5);
	events.emplace_back(temp);
	++eventsCount;
}
string Pedometer::FindEvents(string p0, int p1, int p2)
{
	string temp = "";
	int day = stoi(p0.substr(0, 2));
	int month = stoi(p0.substr(3, 2));
	int year = stoi(p0.substr(6, 9));
	for (int i = 0; i < eventsCount; ++i)
	{
		if (events[i].year == year && events[i].month == month && events[i].day == day && events[i].startTime >= p1 && events[i].endTime <= p2)
			temp += to_string(events[i].startTime / 60) + ':' + to_string(events[i].startTime % 60) + " - " + to_string(events[i].endTime / 60) + ':' + to_string(events[i].endTime % 60) + ' ' + to_string(events[i].count) + " шагов\n";
	}
	if (temp != "")
		return temp;
	else
		return "Не найдено ни одного подсчета!";
}
ostream& operator<< (ostream& stream, const Pedometer& ped)
{
	stream << ped.eventsCount;
	for (int i = 0; i < ped.eventsCount; ++i)
		stream << ped.events[i];
	stream << endl;
	return stream;
}
istream& operator>> (istream& stream, Pedometer& ped)
{
	stream >> ped.eventsCount;
	if (ped.eventsCount != 0)
		ped.events.clear();
	Event temp;
	for (int i = 0; i < ped.eventsCount; ++i)
	{
		ped.events.emplace_back(temp);
		stream >> ped.events[i];
	}
	return stream;
}

Pedometer::Pedometer()
{
	eventsCount = 0;
}
Pedometer::Pedometer(int event_count)
{
	eventsCount = event_count;
	string p0;
	int p1, p2, p3, p4, p5;
	Event temp;
	for (int i = 0; i < event_count; ++i)
	{
		cin >> p0 >> p1 >> p2 >> p3 >> p4 >> p5;
		temp.Inic(p0, p1, p2, p3, p4, p5);
		events.emplace_back(temp);
	}
}
Pedometer::Pedometer(string path)
{
	ifstream file;
	file.open(path);
	file >> *this;
	file.close();
}
Pedometer::~Pedometer()
{
	events.clear();
}