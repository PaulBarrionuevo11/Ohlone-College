#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "userMenu.h"
#include "menuOption.h"

using namespace std;

UserMenu::UserMenu() : Menu("Manage User Accounts") {

	MenuOption o1('1', "Open new account", "Show details");
	addOption(o1);
	MenuOption o2('2', "Log into the existing account", "Show details");
	addOption(o2);
	MenuOption o3('3', "Logout", "Show details");
	addOption(o3);
	MenuOption o4('4', "Remove Account", "Show details");
	addOption(o4);
	MenuOption o5('5', "Reset Password", "Reset password needs role=1...");
	addOption(o5);
	MenuOption o6('6', "Help", "Instruction how to use this application");
	addOption(o6);
	MenuOption o7('x', "Quit", "Enter char 'x' to exit user menu and invoke the member method logout");
	addOption(o7);

	initData();
}

UserMenu::~UserMenu() {
	saveData();
}

void UserMenu::saveData() {
	ofstream outfile(USERS_DATA);
	if (!outfile) {
		cout << "Error: Unable to open file " << USERS_DATA << " for writing." << endl;
		return;
	}
	outfile << "ID,UserName,password,Role,Email,Create DateTime,Login DateTime,Logout DateTime" << endl;
	for (int i = 0; i < users.size(); i++) {
		outfile << users[i].to_csv() << endl;
	}
	outfile.close();
}

void UserMenu::activate() {
	// Start the userMenu
	int y = -1;
	do {
		y = getInput();
		switch (y) {
		case USER_CREATE:
			create();
			break;
		case USER_LOGIN:
			login();
			break;
		case USER_LOGOUT:
			logout();
			break;
		case USER_REMOVE:
			remove();
			break;
		case USER_RESET:
			reset();
			break;
		case USER_HELP:
			help();
			break;
		case USER_EXIT:
			cout << "Bye!" << endl;
			break;
		default:
			cout << "Invalid option" << endl;
		}
	} while (y != USER_EXIT);
}

void UserMenu::initData() {
	inFile.open(USERS_DATA);

	if (!inFile) {// Returns error if file error occurs
		cout << "Error opening file: " << USERS_DATA << endl;
		return;
	}

	string line, text;
	int id = 0, role = 0;
	string srole, username, password, createText, signInText, signOutText, email;
	int count = 0;
	while (getline(inFile, line)) {
		istringstream ss(line);
		if (count != 0) {
			getline(ss, text, ',');
			id = stoi(text);
			getline(ss, username, ',');
			getline(ss, password, ',');
			getline(ss, srole, ',');
			role = stoi(srole);
			getline(ss, email, ',');
			getline(ss, createText, ',');
			getline(ss, signInText, ',');
			getline(ss, signOutText, '\r');
			// Populate User data here
			User _user;
			_user.setId(id);
			_user.setEmail(email);
			_user.setUsername(username);
			_user.setPassword(password);
			_user.setRole(role);
			DateTime _createDt(createText);
			_user.setCreateDateTime(_createDt);
			DateTime _signInDt(signInText);
			_user.setLoginDateTime(_signInDt);
			DateTime _signOutDt(signOutText);
			_user.setLogoutDateTime(_signOutDt);
			users.push_back(_user);
		}
		count++;
	}

	inFile.close();
}

bool UserMenu::login() {
	int attempt = 0;
	do {
		if (attempt > 0) {
			cout << "You have " << 3 - attempt << " more attempts.\n";
		}
		cout << "Enter Username or Email: ";
		string name;
		cin >> name;
		int index = (int)name.find('@');

		cout << "Enter password: ";
		string pwd;
		cin >> pwd;
		User _user;

		_user.setPassword(pwd);
		if (index != -1) {
			_user.setEmail(name);
		}
		else {
			_user.setUsername(name);
		}

		if (doLogin(_user)) {
			cout << "You have successfully signed in." << endl;
			return true;
		}
	} while (++attempt < 3);

	cout << "You have no more attempts." << endl;
	return false;
}

bool UserMenu::doLogin(User& _user) {
	bool valid = false;
	for (int i = 0; i < users.size(); i++) {
		User user_ = users.at(i);
		if (_user.getUsername() == user_.getUsername() &&
			_user.getPassword() == user_.getPassword()) {
			valid = true;
			DateTime dtNow;
			users.at(i).setLoginDateTime(dtNow.now());	// Save the login DateTime
			user = user_;
			break;
		}
	}
	return valid;
}

void UserMenu::logout() {
	// Add a member method logout and update the logout system datetime and save user to users_data.csv
}

void UserMenu::create() {
	// Add a member method to create a new user and update the list of users
	string username, password, email;
	int nId;
	User user;
	DateTime dateTime;

	// Get user details
	cout << "Enter username: ";
	cin >> username;
	user.setUsername(username);

	cout << "Enter password: ";
	cin >> password;
	user.setPassword(password);

	cout << "Enter email: ";
	cin >> email;
	user.setEmail(email);

	// Set other user attributes
	user.setRole(0); // Default role (consider replacing '0' with a named constant or enum)
	user.setCreateDateTime(dateTime.now());

	// Generate a new ID based on the current size of the `users` list
	nId = users.size() + 1000; // New ID is the size of the list
	user.setId(nId);

	// Add the user to the list
	try {
		users.push_back(user);
		cout << "User created successfully!" << endl;
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (...) {
		cout << "An unknown error occurred." << endl;
	}
}


void UserMenu::remove() {
	// Add a member method remove exist user
}

void UserMenu::reset() {
	// Add a member method reset account definition and implementation. Only the admin user will be able to reset the password
}

void UserMenu::help() {
	// Show the cout instructions on how to use this application
}