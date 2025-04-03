#pragma once
#include <string>

using namespace std;

class Date {
public:
	Date();
	Date(int m, int d, int y);

	void setDate(string dateString);

	void setMonth(int m) { month = m; };
	void setDay(int d) { day = d; };
	void setYear(int y) { year = y; };

	int getMonth() { return month; };
	int getDay() { return day; };
	int getYear() { return year; };

	Date& getDate() { return *this; };

	string toString() const;

	Date operator+(const int minutes) const;
	int operator-(const Date&) const;
	bool operator==(const Date&) const;
	bool operator!=(const Date&) const;
	bool operator<(const Date&) const;

	friend istream& operator>>(istream& in, Date& a); // cin
	friend ostream& operator<<(ostream& out, Date a); // cout
protected:
	int month;
	int day;
	int year;
};