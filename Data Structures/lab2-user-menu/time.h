#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time {
protected:
    int hour, minute, second;
    string time;

public:
    // Constructors
    Time();
    Time(int hour, int minute, int second);

    // Accessors
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void setMinutes(int _m);
    void setHours(int _h);
    void setSeconds(int _s);
    void setTime(string _time);

    // Overload << operator for Time
    friend std::ostream& operator<<(std::ostream& os, const Time& time);
};

#endif
