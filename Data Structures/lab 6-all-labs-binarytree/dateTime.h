#pragma once
#include <ostream>
#include "date.h"
#include "time.h"

using namespace std;

class DateTime : public Date, public Time {

public:
	DateTime();
	DateTime(DateTime& dt);
	DateTime(string s);
	DateTime(int m, int d, int y, int hr, int min, int sec);

	void setDateTime(string dt);

	DateTime& now();
	string toString() const;

	// Assignment operator overloading
	DateTime& operator=(const DateTime&);

	// You may need these operators for comparing datetime

	//bool operator>(const DateTime&) const;
	//bool operator<(const DateTime&) const;
	//bool operator>=(const DateTime&) const;
	//bool operator<=(const DateTime&) const;

	// Overloaded operators
	friend ostream& operator<<(ostream& out, const DateTime& dt);
	friend istream& operator>>(istream& in, DateTime& dt);

private:
};