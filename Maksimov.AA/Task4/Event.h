#pragma once
using namespace std;
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <locale.h>
#include <string>
#include <math.h>
#include <windows.h>
#include <conio.h>

class Event
{
public:
	int startTime; // в минутах
	int endTime; // в минутах
	int year; // год
	int month; // месяц
	int day; // день
	int count; // количество шагов
	Event() {};
	void Inic(string date, int start_hour, int start_min, int end_hour, int end_min, int _count); // инициализация события
	string GetDate(); // получение даты
	Event& Event::operator= (const Event& d); // =
	friend ostream& operator<< (ostream& stream, const Event& ev); // вывод
	friend istream& operator>> (istream& stream, Event& ev); // ввод
};