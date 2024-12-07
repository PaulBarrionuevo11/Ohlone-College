#ifndef USER_H
#define USER_H

#include <string>
#include <ostream>
#include <istream>
#include "dateTime.h"

using namespace std;

class User {
public:
	User() = default;
	User(const User&);

	void setId(int);			// UserId
	void setEmail(string);		// Either email or username may be used to login
	void setUsername(string);		// Username to login
	void setPassword(string);		// User password
	void setRole(int);			// Role=1 (admin);Role=2(user); Role=-1 (guess)
	void setCreateDateTime(DateTime);	// Login create user date time
	void setLoginDateTime(DateTime);	// Login date time
	void setLogoutDateTime(DateTime); // Logout date time

	int getId() { return id; };
	string getEmail() { return email; };
	string getUsername() { return username; };
	string getPassword() { return password; };
	int getRole() { return role; };
	DateTime getCreateDateTime() { return createDt; };
	DateTime getLoginDateTime() { return loginDt; };
	DateTime getLogoutDateTime() { return logoutDt; };

	string to_csv();

	
	bool operator==(const User&);
	/*
	bool operator!=(const User&) const;
	bool operator>(const User&) const;
	bool operator<(const User&) const;
	bool operator>=(const User&) const;
	bool operator<=(const User&) const;

	//friend istream& operator>>(istream& in, User& a); // cin
	*/
private:
	int id;				// UserId
	string email;		// Either email or username may be used to login
	string username;	// Username to login
	string password;	// User password
	int role;			// Role=1 (admin);Role=2(user); Role=-1 (guess)
	DateTime createDt;	// Login create user date time
	DateTime loginDt;	// Login date time
	DateTime logoutDt;	// Logout date time
};

#endif