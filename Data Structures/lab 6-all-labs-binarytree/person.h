#ifndef PERSON_H
#define	PERSON_H

#include <iostream>

using namespace std;

class Person
{
	// Implement a new class Person, including all the necessary data, methods, and operators
public:
	Person(int id, string fName, string mName, string lName, string company,
		string address, string city, string county, string state, string zip, string phone1, string phone2, string email);
	Person() = default;
	~Person();

	//static string fieldNameSort;

	// Getters
	int getId() const;
	string getZip() const;
	string getPhone1() const;
	string getPhone2() const;
	string getFirstName() const;
	string getMiddleName() const;
	string getLastName() const;
	string getCompany() const;
	string getAddress() const;
	string getCity() const;
	string getCounty() const;
	string getState() const;
	string getEmail() const;

	// Setters
	void setId(int _id);
	void setZip(string _zip);
	void setPhone1(string _phone1);
	void setPhone2(string _phone2);
	void setFirstName(string _fn);
	void setMiddleName(string _mn);
	void setLastName(string _ln);
	void setCompany(string _company);
	void setAddress(string _address);
	void setCity(string _city);
	void setCounty(string _county);
	void setState(string _state);
	void setEmail(string _email);

	Person& operator=(const Person& p);
	bool operator<(const Person& p) const;
	bool operator>(const Person& p) const;
	bool operator<=(const Person& p) const;
	bool operator==(const Person& p) const;

	friend ostream& operator<<(ostream& os, const Person& p);




private:
	int id;
	string firstName, middleName, lastName, company, address, city, county, state, email, phone1, phone2, zip;

};
#endif // !PERSON_H
