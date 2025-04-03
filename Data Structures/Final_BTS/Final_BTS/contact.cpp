#include "contact.h"
#include "iomanip"

/*******************************************************
 * Function Name: Contact::Contact
 * Purpose: Constructor to initialize a Contact object with provided data.
 * Parameter:
 *   id - Unique identifier for the contact.
 *   fName - First name of the contact.
 *   mName - Middle name of the contact.
 *   lName - Last name of the contact.
 *   c - Company name associated with the contact.
 *   add - Address of the contact.
 *   city - City where the contact resides.
 *   county - County of the contact.
 *   state - State where the contact resides.
 *   zip - Zip code of the contact.
 *   phone1 - Primary phone number.
 *   phone2 - Secondary phone number.
 *   email - Email address of the contact.
 * Return: None (constructor).
 *******************************************************/
Contact::Contact(string fName, string mName, string lName, string c,
	string add, string city, string county, string state, string zip, string phone1, string phone2, string email)
	: firstName(fName), middleName(mName), lastName(lName), company(c), address(add),
	city(city), county(county), state(state), zip(zip), phone1(phone1), phone2(phone2), email(email)
{
}
Contact::~Contact()
{

}
/*******************************************************
 * Function Name: Contact::operator=
 * Purpose: Overloaded assignment operator for Contact objects.
 * Parameter:
 *   p - A reference to the Contact object to copy from.
 * Return: A reference to the current Contact object (*this).
 *******************************************************/
Contact& Contact::operator=(const Contact& p)
{
	if (this != &p) {  // Prevent self-assignment
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
/*******************************************************
 * Function Name: Contact::operator<
 * Purpose: Overloaded less-than operator for comparison of Contact objects.
 * Parameter:
 *   other - A reference to the Contact object to compare against.
 * Return: True if the current object is less than the other, otherwise false.
 *******************************************************/
bool Contact::operator<(const Contact& other) const {
	if (firstName != other.firstName)
		return firstName < other.firstName;
	if (middleName != other.middleName)
		return middleName < other.middleName;
}
/*******************************************************
 * Function Name: Contact::operator<=
 * Purpose: Overloaded less-than-or-equal-to operator for Contact objects.
 * Parameter:
 *   p - A reference to the Contact object to compare against.
 * Return: True if the current object is less than or equal to the other, otherwise false.
 *******************************************************/
bool Contact::operator<=(const Contact& p) const {
	return *this < p || *this == p;
}
/*******************************************************
 * Function Name: Contact::operator==
 * Purpose: Overloaded equality operator for Contact objects.
 * Parameter:
 *   p - A reference to the Contact object to compare against.
 * Return: True if all fields are equal, otherwise false.
 *******************************************************/
bool Contact::operator==(const Contact& p) const {
	return firstName == p.firstName &&
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
/*******************************************************
 * Function Name: Contact::operator>
 * Purpose: Overloaded greater-than operator for Contact objects.
 * Parameter:
 *   other - A reference to the Contact object to compare against.
 * Return: True if the current object is greater than the other, otherwise false.
 *******************************************************/
bool Contact::operator>(const Contact& other) const {
	return other < *this;
}
/*******************************************************
 * Function Name: operator<<
 * Purpose: Overloaded output stream operator for Contact objects.
 * Parameter:
 *   os - A reference to the output stream.
 *   p - A reference to the Contact object to output.
 * Return: A reference to the output stream.
 *******************************************************/
ostream& operator<<(ostream& os, const Contact& p) {
	os << std::left; // Align text to the left

	// Use adjusted column widths
	os << std::setw(12) << (p.firstName.size() > 14 ? p.firstName.substr(0, 12) + "..." : p.firstName)
		<< std::setw(15) << (p.middleName.size() > 14 ? p.middleName.substr(0, 12) + "..." : p.middleName)
		<< std::setw(15) << (p.lastName.size() > 14 ? p.lastName.substr(0, 12) + "..." : p.lastName)
		<< std::setw(20) << (p.company.size() > 19 ? p.company.substr(0, 17) + "..." : p.company)
		<< std::setw(25) << (p.address.size() > 24 ? p.address.substr(0, 22) + "..." : p.address)
		<< std::setw(15) << (p.city.size() > 14 ? p.city.substr(0, 12) + "..." : p.city)
		<< std::setw(15) << (p.county.size() > 14 ? p.county.substr(0, 12) + "..." : p.county)
		<< std::setw(10) << p.state
		<< std::setw(8) << p.zip
		<< std::setw(15) << p.phone1
		<< std::setw(15) << p.phone2
		<< std::setw(25) << (p.email.size() > 24 ? p.email.substr(0, 22) + "..." : p.email);
	return os;
}

/******** SETTERS *******/
void Contact::setZip(string _zip)
{
	zip = _zip;
}
void Contact::setPhone1(string _phone1)
{
	phone1 = _phone1;
}
void Contact::setPhone2(string _phone2)
{
	phone2 = _phone2;
}
void Contact::setFirstName(string _fn)
{
	firstName = _fn;
}
void Contact::setMiddleName(string _mn)
{
	middleName = _mn;
}
void Contact::setLastName(string _ln)
{
	lastName = _ln;
}
void Contact::setCompany(string _company)
{
	company = _company;
}
void Contact::setAddress(string _address)
{
	address = _address;
}
void Contact::setCity(string _city)
{
	city = _city;
}
void Contact::setCounty(string _county)
{
	county = _county;
}
void Contact::setState(string _state)
{
	state = _state;
}
void Contact::setEmail(string _email)
{
	email = _email;
}
/******** GETTERS *******/
string Contact::getZip() const
{
	return zip;
}
string Contact::getPhone1() const
{
	return phone1;
}
string Contact::getPhone2() const
{
	return phone2;
}
string Contact::getFirstName() const
{
	return firstName;
}
string Contact::getMiddleName() const
{
	return middleName;
}
string Contact::getLastName() const
{
	return lastName;
}
string Contact::getCompany() const
{
	return company;
}
string Contact::getAddress() const
{
	return address;
}
string Contact::getCity() const
{
	return city;
}
string Contact::getCounty() const
{
	return county;
}
string Contact::getState() const
{
	return state;
}
string Contact::getEmail() const
{
	return email;
}