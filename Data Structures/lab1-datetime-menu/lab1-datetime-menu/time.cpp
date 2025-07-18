#include "time.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

/*******************************************************
 * Function Name: Time Constructor
 * Purpose: Builds an empty constructor of the class
 *******************************************************/
Time::Time()
{
	this->hour = 20;
	this->minute = 20;
	this->second = 22;
}
/*******************************************************
 * Function Name: Time Destructor
 * Purpose: Destroys the constructor of class Time
 *******************************************************/
Time::~Time()
{
}
/*******************************************************
 * Function Name: display()
 * Purpose: Displays the time hours minutes and seconds from the class methods
 * Return: Console out of the methods getHour, get Minute and getSecond
 *******************************************************/
void Time::display()
{
	cout << toString() << endl;
}
/*******************************************************
 * Function Name: getHour()
 * Purpose: Gets time's hour
 * Return: Class private attribute
 *******************************************************/
int Time::getHour() const
{
	return this->hour;
}
/*******************************************************
 * Function Name: setHour()
 * Purpose: Sets time's hour
 * Parameter: hour_ hours in time
 *******************************************************/
void Time::setHour(int _hour)
{
	this->hour = _hour;
}
/*******************************************************
 * Function Name: getMinute()
 * Purpose: Gets time's minute
 * Return: Class private attribute
 *******************************************************/
int Time::getMinute() const
{
	return this->minute;
}
/*******************************************************
 * Function Name: setMinute()
 * Purpose: Sets time's minute
 * Parameter: minute_ minutes in time
 *******************************************************/
void Time::setMinute(int _minute)
{
	this->minute = _minute;
}
/*******************************************************
 * Function Name: getSecond()
 * Purpose: Gets time's second
 * Return: Class private attribute
 *******************************************************/
int Time::getSecond() const
{
	return this->second;
}
/*******************************************************
 * Function Name: setSecond()
 * Purpose: Sets time's second
 * Parameter: second_ seconds in time
 *******************************************************/
void Time::setSecond(int _second)
{
	this->second = _second;
}
/*******************************************************
 * Function Name: toString()
 * Purpose: Sets time into string
 * Return: returns string with all the getter methods
 *******************************************************/
string Time::toString() const
{	
	string result = to_string(getHour()) + ":" + to_string(getMinute()) + ":" + to_string(getSecond());
	return result;
}
/*******************************************************
 * Function Name: getSystemTime()
 * Purpose: Gets the time from the machine
 * Return: returns string with the current time
 *******************************************************/
string Time::getSystemTime() const
{
	// Get the current time point
	auto now = chrono::system_clock::now();

	// Convert to time_t for localtime
	std::time_t currentTime = chrono::system_clock::to_time_t(now);

	// Convert to local time
	std::tm localTime;
	localtime_s(&localTime, &currentTime);

	// Format the time as a string
	ostringstream timeStream;
	timeStream << put_time(&localTime, "%H:%M:%S");

	// Return the formatted time as a string
	return timeStream.str();

}

