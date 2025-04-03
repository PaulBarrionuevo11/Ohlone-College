#include "date.h"
#include "time.h"
#include "dateTime.h"
#include <ctime>

/*******************************************************
 * Function Name: DateTime Constructor
 * Purpose: Builds an empty constructor of the class
 *******************************************************/
DateTime::DateTime()
{
}
/*******************************************************
 * Function Name: getDate()
 * Purpose: Gets time from Date class
 * Return: date object
 *******************************************************/
Date DateTime::getDate()
{
	Date date;
	date.setMonth(getMonth());
	date.setDay(getDay());
	date.setYear(getYear());
	return date;
}
/*******************************************************
 * Function Name: getTime()
 * Purpose: Gets time from Time class
 * Return: time object
 *******************************************************/
Time DateTime::getTime()
{
	Time time;
	time.setHour(getHour());
	time.setMinute(getMinute());
	time.setSecond(getSecond());
	return time;
}
/*******************************************************
 * Function Name: display()
 * Purpose: Displays the date time separated with space
 * Return: Console out of the date time
 *******************************************************/
void DateTime::display()
{
	cout << toString() << endl;
}
/*******************************************************
 * Function Name: toString()
 * Purpose: Sets date and time to string
 * Return: returns string with all the toString methods
 * from the Time and Date class
 *******************************************************/
 string DateTime::toString() const
{	
	 string result = Date::toString() + " " + Time::toString();
	 return result;
}

