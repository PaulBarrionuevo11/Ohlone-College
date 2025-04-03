#include "date.h"
#include "time.h"
#include "dateTime.h"
#include <ctime>

/*******************************************************
 * Function Name: DateTime Constructor
 * Purpose: Builds an empty constructor of the class
 *******************************************************/
DateTime::DateTime() : Date(), Time()
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
 DateTime& DateTime::now() {
	 time_t now = time(nullptr);
	 tm* lt = localtime(&now);
	 setYear(1900 + lt->tm_year);
	 setMonth(lt->tm_mon);
	 setDay(lt->tm_mday);
	 setHour(lt->tm_hour);
	 setMinute(lt->tm_min);
	 setSecond(lt->tm_sec);
	 return *this;
 }


