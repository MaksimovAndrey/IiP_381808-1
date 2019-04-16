#include "Event.h";

void Event::Inic(string date, int start_hour, int start_min, int end_hour, int end_min, int _count)
{
	// date = "11.02.2019"
	day = stoi(date.substr(0, 2));
	month = stoi(date.substr(3, 2));
	year = stoi(date.substr(6, 9));
	startTime = start_hour * 60 + start_min;
	endTime = end_hour * 60 + end_min;
	count = _count;
}
string Event::GetDate()
{
	string temp = "";
	if (day > 9)
		temp += to_string(day);
	else
		temp += '0' + to_string(day);
	temp += '.';
	if (month > 9)
		temp += to_string(month);
	else
		temp += '0' + to_string(month);
	temp += '.' + to_string(year);
	return temp;
}
Event& Event::operator= (const Event& d)
{
	startTime = d.startTime;
	endTime = d.endTime;
	year = d.year;
	month = d.month;
	day = d.day;
	count = d.count;
	return *this;
}
ostream& operator<< (ostream& stream, const Event& ev)
{
	Event temp = ev;
	stream << '\n' << temp.GetDate() << ' ' << ev.startTime / 60 << ' ' << ev.startTime % 60 << ' ' << ev.endTime / 60 << ' ' << ev.endTime % 60 << ' ' << ev.count;
	return stream;
}
istream& operator>> (istream& stream, Event& ev)
{
	string p0;
	int p1, p2, p3, p4, p5;
	stream >> p0 >> p1 >> p2 >> p3 >> p4 >> p5;
	ev.Inic(p0, p1, p2, p3, p4, p5);
	return stream;
}