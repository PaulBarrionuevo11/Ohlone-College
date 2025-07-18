#pragma once
#include <iostream>
#include <ostream>

using namespace std;
class Time {

public:
	Time();
	Time(int h, int m);
	Time(int h, int m, int sec);
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	int getHour() { return hour; };
	int getMinute() { return minute; };
	int getSecond() { return second; };

	Time& getTime() { return *this; };

	string toString() const;

	Time operator+(const int minutes) const;
	int operator-(const Time&) const;
	bool operator==(const Time&) const;
	bool operator!=(const Time&) const;
	bool operator<(const Time&) const;

	friend istream& operator>>(istream& in, Time& a); // cin
	friend ostream& operator<<(ostream& out, Time a); // cout
protected:
	int hour;
	int minute;
	int second;
};