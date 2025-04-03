#ifndef DATA_EXCEPTION_H
#define DATA_EXCEPTION_H

#include <iostream>

using namespace std;

class DataException
{
public:
	DataException();
	~DataException();



private:
	// File path to course data
	string COURSE_DATA = "C:/Users/pable/Documents/Ohlone/Data Structures/Downloads/courses_data.dat";
	string FACULTY_DATA = "C:/Users/pable/Documents/Ohlone/Data Structures/Downloads/faculty_data.csv";

};

DataException::DataException()
{
}

DataException::~DataException()
{
}
#endif // !DATA_EXCEPTION_H
