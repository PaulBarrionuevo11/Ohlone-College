#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>

using namespace std;

class Time
{
public:

	Time(); // Constructor with no arguments
	~Time(); // Destructor
	void display(); // display time only
	int getHour() const; // Get current hour
	void setHour(int _hour);
	int getMinute() const; // Get current minute
	void setMinute(int _minute);
	int getSecond() const; // Get current second
	void setSecond(int _second);
	string toString() const;
	string getSystemTime() const;

private:
	// Private attributes
	int hour;
	int minute;
	int second;
};
#endif // !TIME_H