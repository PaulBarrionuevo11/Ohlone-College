#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
protected:
    int year, month, day;
    //string date;
public:
    // Constructors
    Date();
    Date(int year, int month, int day);

    // Accessors
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void setMonth(int _month);
    void setYear(int _year);
    void setDay(int _day);
    //void setDate(string _date);

    // Overload << operator for Date
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif
