#ifndef DATA_EXCEPTION_H
#define DATA_EXCEPTION_H

#include <iostream>

using namespace std;

class DataException
{
public:
	DataException()
	{
		message = "Something went wrong";
	}
	DataException(string data)
	{
		data = message;
	}
	string what()
	{
		return message;
	}
private:
	string message;

};
#endif // !DATA_EXCEPTION_H
