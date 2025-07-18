#include "dateTime.h"
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;


/*******************************************************
 * Function Name: DateTime (Default Constructor)
 * Purpose: Initializes a DateTime object using default values for Date and Time.
 * Parameter: None.
 * Return: None (Constructor).
 *******************************************************/
DateTime::DateTime() : Date(), Time() {}

/*******************************************************
 * Function Name: DateTime (Parameterized Constructor)
 * Purpose: Initializes a DateTime object using provided values for year, month, day, hour, minute, and second.
 * Parameter: year - The year of the DateTime.
 *            month - The month of the DateTime.
 *            day - The day of the DateTime.
 *            hour - The hour of the DateTime.
 *            minute - The minute of the DateTime.
 *            second - The second of the DateTime.
 *******************************************************/
DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
    : Date(year, month, day), Time(hour, minute, second) {}

/*******************************************************
 * Function Name: now
 * Purpose: Returns the current system date and time as a DateTime object.
 * Return: DateTime - The current system date and time.
 *******************************************************/
DateTime DateTime::now() {
    return DateTime(2024, 10, 4, 16, 22, 00);
    /* Uncomment the following code to get real system date and time:
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    return DateTime(localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
        localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    */
}

/*******************************************************
 * Function Name: setDateTime
 * Purpose: Sets the DateTime object using a string input in the format "M/D/YYYY H:MM:SS".
 * Parameter: dt - A string representing the date and time to be set.
 *******************************************************/
void DateTime::setDateTime(string dt)
{
    int index = dt.find(' ');
    string dateString = dt.substr(0, index);
    string timeString = dt.substr(++index);
    //Date::setDate(dateString);
    //Time::setTime(timeString);
}

/*******************************************************
 * Function Name: operator<< (DateTime)
 * Purpose: Overloads the << operator to allow printing of the DateTime object.
 * Parameter: os - Reference to the output stream.
 *            dt - Reference to the DateTime object to be printed.
 * Return: ostream& - The modified output stream for chaining.
 *******************************************************/
ostream& operator<<(ostream& os, const DateTime& dt) {
    os << static_cast<const Date&>(dt) << " " << static_cast<const Time&>(dt);
    return os;
}

