#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>

using namespace std;

class Faculty
{
public:
	Faculty() : instructor(""), firstName(""), lastName(""), department(""),
		address(""), city(""), state(""), zip(""), email(""), phone("") {}
	~Faculty() {}

	// Getters
	string getInstructor() { return instructor; }
	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	string getDepartment() { return department; }
	string getAddress() { return address; }
	string getCity() { return city; }
	string getState() { return state; }
	string getZip() { return zip; }
	string getEmail() { return email; }
	string getPhone() { return phone; }
	// Setters 
	void setInstructor(string _inst) { instructor = _inst; }
	void setFirstName(string _firstN) { firstName = _firstN; }
	void setLastName(string _lastN) { lastName = _lastN; }
	void setDepartment(string _dep) { department = _dep; }
	void setAddress(string _addr) { address = _addr; }
	void setCity(string _city) { city = _city; }
	void setState(string _state) { state = _state; }
	void setZip(string _zip) { zip = _zip; }
	void setEmail(string _email) { email = _email; }
	void setPhone(string _phone) { phone = _phone; }

	bool operator==(const Faculty& p) const
	{
		return this->instructor == p.instructor;
	}
	friend ostream& operator<<(ostream& os, const Faculty& a)
	{
		os << "Instructor ID: " << a.instructor << "\n"
			<< "First Name: " << a.firstName << "\n"
			<< "Last Name: " << a.lastName << "\n"
			<< "Department: " << a.department << "\n"
			<< "Address: " << a.address << "\n"
			<< "City: " << a.city << "\n"
			<< "State: " << a.state << "\n"
			<< "Zip: " << a.zip << "\n"
			<< "Email: " << a.email << "\n"
			<< "Phone: " << a.phone << "\n";
		return os;
	}

private:
	string instructor, firstName, lastName, department, address, city, state, zip, email, phone;

};
#endif // !FACULTY_H