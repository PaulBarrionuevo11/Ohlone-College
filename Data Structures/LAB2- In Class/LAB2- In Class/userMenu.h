#ifndef USER_MENU_H
#define USER_MENU_H

#include <fstream>
#include <vector>
#include "menu.h"
#include "user.h"

using namespace std;

const string USERS_DATA = "C:/Users/pable/Downloads/lab2-userMenu/users_data.csv";

enum USER_OPTION {
	USER_CREATE = '1',
	USER_LOGIN = '2',
	USER_LOGOUT = '3',
	USER_REMOVE = '4',
	USER_RESET = '5',
	USER_HELP = '6',
	USER_EXIT = 'x'
};

class UserMenu : public Menu {

public:
	UserMenu();
	~UserMenu();
	User user;			// Login user


	void activate(); // Start the userMenu
	bool login();  // Add a member method login and update the login system datetime. Your method login should allow 3 retries if the user enters an invalid username and password. If the user enters a valid username and password, output a message to indicate successful login or error
	void logout(); // Add a member method logout and update the logout system datetime and save user to users_data.csv
	void create(); // Add a member method create new user and update the list of users
	void remove(); // Add a member method remove exist user
	void reset();  // Add a member method reset account definition and implementation. Only the admin user will be able to reset the password
	void help();   // Show the cout instructions on how to use this application

private:
	fstream inFile;		// Use <fstream> to read the users_data.csv
	vector<User> users; // List of available vector<users>

	bool doLogin(User&);
	void initData();		// Read data from users_data.csv; and populate the list
	void saveData();
};

#endif