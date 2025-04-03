#ifndef DATETIME_H
#define DATETIME_H

#include "date.h"
#include "time.h"
#include <iostream>
#include <string>


using namespace std;

class DateTime : public Date, public Time
{
public:
	DateTime(); // Class constructor
	DateTime& now();
	Time getTime(); // Method of type Time
	Date getDate(); // Method of type Date
	void display(); // Display date & time only
	// Display date and type in string
	string toString() const;
private:
};
#endif // !DATETIME_H