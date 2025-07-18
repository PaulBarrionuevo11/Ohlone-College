#include "person.h"

Person::Person(int id, string fName, string mName, string lName, string c,
	string add, string city, string county, string state, string zip, string phone1, string phone2, string email)
	: id(id), firstName(fName), middleName(mName), lastName(lName), company(c), address(add),
	city(city), county(county), state(state), zip(zip), phone1(phone1), phone2(phone2), email(email)
{
}
Person::~Person()
{

}

//string Person::fieldNameSort = "id"; // default by fieldname id

Person& Person::operator=(const Person& p)
{
	if (this != &p) {  // Prevent self-assignment
		id = p.id;
		firstName = p.firstName;
		middleName = p.middleName;
		lastName = p.lastName;
		company = p.company;
		address = p.address;
		city = p.city;
		county = p.county;
		state = p.state;
		zip = p.zip;
		phone1 = p.phone1;
		phone2 = p.phone2;
		email = p.email;
	}
	return *this;
}
bool Person::operator<(const Person& other) const {
	if (firstName != other.firstName)
		return firstName < other.firstName;
	if (middleName != other.middleName)
		return middleName < other.middleName;
	return id < other.id;
}
// Comparison operators based on "<"
bool Person::operator<=(const Person& p) const {
	return *this < p || *this == p;
}
bool Person::operator==(const Person& p) const {
	return id == p.id &&
		firstName == p.firstName &&
		middleName == p.middleName &&
		lastName == p.lastName &&
		company == p.company &&
		address == p.address &&
		city == p.city &&
		county == p.county &&
		state == p.state &&
		zip == p.zip &&
		phone1 == p.phone1 &&
		phone2 == p.phone2 &&
		email == p.email;
}
bool Person::operator>(const Person& other) const {
	return other < *this;
}
ostream& operator<<(ostream& os, const Person& p) {
	// Print members of obj to os
	os << p.id << "  " << p.firstName << "  " << p.middleName << "  " << p.lastName <<
		p.company << "  " << p.address << "  " << p.city << "  " << p.county << "  " <<
		p.state << "  " << p.zip << "  " << p.phone1 << "  " << p.phone2 << "  " <<
		p.email;
	return os;
}

// Setters
void Person::setId(int _id)
{
	id = _id;
}
void Person::setZip(string _zip)
{
	zip = _zip;
}
void Person::setPhone1(string _phone1)
{
	phone1 = _phone1;
}
void Person::setPhone2(string _phone2)
{
	phone2 = _phone2;
}
void Person::setFirstName(string _fn)
{
	firstName = _fn;
}
void Person::setMiddleName(string _mn)
{
	middleName = _mn;
}
void Person::setLastName(string _ln)
{
	lastName = _ln;
}
void Person::setCompany(string _company)
{
	company = _company;
}
void Person::setAddress(string _address)
{
	address = _address;
}
void Person::setCity(string _city)
{
	city = _city;
}
void Person::setCounty(string _county)
{
	county = _county;
}
void Person::setState(string _state)
{
	state = _state;
}
void Person::setEmail(string _email)
{
	email = _email;
}
// Getters
int Person::getId() const
{
	return id;
}
string Person::getZip() const
{
	return zip;
}
string Person::getPhone1() const
{
	return phone1;
}
string Person::getPhone2() const
{
	return phone2;
}
string Person::getFirstName() const
{
	return firstName;
}
string Person::getMiddleName() const
{
	return middleName;
}
string Person::getLastName() const
{
	return lastName;
}
string Person::getCompany() const
{
	return company;
}
string Person::getAddress() const
{
	return address;
}
string Person::getCity() const
{
	return city;
}
string Person::getCounty() const
{
	return county;
}
string Person::getState() const
{
	return state;
}
string Person::getEmail() const
{
	return email;
}


