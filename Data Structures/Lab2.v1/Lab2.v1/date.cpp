#include "date.h"
#include <iomanip>
#include <iostream>

using namespace std;

// Default constructor
Date::Date() : year(1970), month(1), day(1) {}

// Parameterized constructor
Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

// Accessor methods
int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
void Date::setDay(int _day) { day = _day; }
void Date::setMonth(int _month) { month = _month; }
void Date::setYear(int _year) { year = _year; }

//void Date::setDate(string _dateString) { date = _dateString; }

// Overload << operator for Date
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << std::setw(4) << std::setfill('0') << date.year << "-"
        << std::setw(2) << std::setfill('0') << date.month << "-"
        << std::setw(2) << std::setfill('0') << date.day;
    return os;
}
