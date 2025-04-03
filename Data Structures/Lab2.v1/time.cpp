#include "time.h"
#include <iomanip>

// Default constructor
Time::Time() : hour(0), minute(0), second(0) {}

// Parameterized constructor
Time::Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}

// Accessor methods
int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }
void Time::setMinutes(int _m) { minute = _m; }
void Time::setHours(int _h) { hour = _h; }
void Time::setSeconds(int _s) { second = _s; }
void Time::setTime(string _time) { time = _time; }

// Overload << operator for Time
std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << std::setw(2) << std::setfill('0') << time.hour << ":"
        << std::setw(2) << std::setfill('0') << time.minute << ":"
        << std::setw(2) << std::setfill('0') << time.second;
    return os;
}
