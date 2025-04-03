#include "date.h"

/*******************************************************
 * Function Name: Date Constructor
 * Purpose: Builds a constructor with day, month and year
 *******************************************************/
Date::Date()
{
	this->day = 14;
	this->month = 9;
	this->year = 2024;
}
/*******************************************************
 * Function Name: Date Destructor
 * Purpose: Destroys the constructor of class Date
 *******************************************************/
Date::~Date()
{
}
/*******************************************************
 * Function Name: display()
 * Purpose: Displays the month, day and year from the class 
 * Return: Console out toString method
 *******************************************************/
void Date::display()
{
	cout <<toString() << endl;
}
/*******************************************************
 * Function Name: getDay()
 * Purpose: Gets date's day
 * Return: Class private attribute
 *******************************************************/
int Date::getDay() const
{
	return this->day;
}
/*******************************************************
 * Function Name: setDay()
 * Purpose: Sets date's day
 * Parameter: _day day in date
 *******************************************************/
void Date::setDay(int _day)
{
	this->day = _day;
}
/*******************************************************
 * Function Name: getMonth()
 * Purpose: Gets date's month
 * Return: Class private attribute
 *******************************************************/
int Date::getMonth() const
{
	return this->month;
}
/*******************************************************
 * Function Name: setMonth()
 * Purpose: Sets date's month
 * Parameter: _month month in date
 *******************************************************/
void Date::setMonth(int _month)
{
	this->month = _month;
}
/*******************************************************
 * Function Name: getYear()
 * Purpose: Gets date's year
 * Return: Class private attribute
 *******************************************************/
int Date::getYear() const
{
	return this->year;
}
/*******************************************************
 * Function Name: setYear()
 * Purpose: Sets date's month
 * Parameter: _year year in date
 *******************************************************/
void Date::setYear(int _year)
{
	this->year = _year;
}
/*******************************************************
 * Function Name: toString()
 * Purpose: Sets date into string
 * Return: returns string with all the getter methods
 *******************************************************/
string Date::toString() const
{
	string result = to_string(getMonth()) + ":" + to_string(getDay()) + ":" + to_string(getYear());
	return result;
}


