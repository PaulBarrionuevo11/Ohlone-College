#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
	Date();			// Constructor with no params
	~Date();		// Destructor
	void display(); // display date only

	/* Getters and setters for month, day and year*/
	int getDay() const;	
	void setDay(int day);
	int getMonth() const;
	void setMonth(int month);
	int getYear() const;
	void setYear(int year);

	string toString() const;	// Pass data as string
private:
	int day;
	int month;
	int year;
};
#endif // !DATE_H