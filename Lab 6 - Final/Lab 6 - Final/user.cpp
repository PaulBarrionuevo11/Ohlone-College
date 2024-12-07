#include <iostream>
#include <string>
#include "user.h"

using namespace std;

User::User(const User& user) {
	id = user.id;
	role = user.role;
	email = user.email;
	username = user.username;
	password = user.password;
	role = user.role;
	createDt = user.createDt;
	loginDt = user.loginDt;
	logoutDt = user.logoutDt;
}

void User::setId(int id) {			// UserId
	this->id = id;
}
void User::setEmail(string email) {
	// Either email or username may be used to login
	this->email = email;
}

void User::setUsername(string uname) {
	username = uname;		// Username to login
}

void User::setPassword(string pwd) {
	password = pwd;		// User password
}

void User::setRole(int _role) {
	role = _role;			// Role=1 (admin);Role=2(user); Role=-1 (guess)
}

void User::setCreateDateTime(DateTime dt) {
	createDt = dt;	// Login create user date time
}

void User::setLoginDateTime(DateTime dt) {
	loginDt = dt;	// Login date time
}

void User::setLogoutDateTime(DateTime dt) { // Logout date time
	logoutDt = dt;
}

string User::to_csv() {
	return to_string(id) + ","
		+ username + ","
		+ password + ","
		+ to_string(role) + ","
		+ email + ","
		+ createDt.toString() + ","
		+ loginDt.toString() + ","
		+ logoutDt.toString();
}

/*
istream& operator>>(istream& in, User& user) {
	cout << "Enter new id: ";
	int id;
	cin >> id;
	user.setId(id);

	cout << "Enter username: ";
	string s;
	cin >> s;
	user.setUsername(s);

	cout << "Enter password: ";
	cin >> s;
	user.setPassword(s);

	cout << "Enter role (Role=1 (admin);Role=2(user): ";
	int role;
	cin >> role;
	user.setRole(role);

	cout << "Enter email: ";
	cin >> s;
	user.setEmail(s);

	// todo... datetime
	return in;
}*/