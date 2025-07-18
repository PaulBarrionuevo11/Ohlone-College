#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include "date.h"
#include "time.h"

class DateTime : public Date, public Time {
public:
    // Constructors
    DateTime();
    DateTime(const Date& dateObj, const Time& timeObj) : date(dateObj), time(timeObj) {}
    DateTime(int year, int month, int day, int hour, int minute, int second);

    // Static method to get the current system date and time
    static DateTime now();
    void setDateTime(string dt);
    // Getter for Date
    Date getDate() const {
        return date;
    }

    // Getter for Time
    Time getTime() const {
        return time;
    }

    // Overload << operator for DateTime
    friend ostream& operator<<(ostream& os, const DateTime& dt);
private:
    Date date;
    Time time;

};

#endif
