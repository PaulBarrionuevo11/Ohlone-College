#include "userMenu.h"
#include "login.h"
#include "dataException.h"
#include "mainMenu.h"
#include <sstream>

/*******************************************************
 * Function Name: LoginMenu Constructor
 * Purpose: Initializes class derived from Menu class
 * giving menu option that will be added to Menu
 *******************************************************/
LoginMenu::LoginMenu() : Menu("Login Menu")
{
	MenuOption op1('1', "Enter your account to login", "Description");
	MenuOption op2('2', "Get Help", "Description");
	MenuOption op3('X', "Exit", "Description");

	addOption(op1);
	addOption(op2);
	addOption(op3);
}
/*******************************************************
 * Function Name: activate() 
 * Purpose: activates menu and allows user to select an option
 *******************************************************/
void LoginMenu::activate()
{
	char choice = 0;
	do {
		choice = getInput();
		switch (choice) {
		case USER_LOGIN:
			login();
			break;
		case USER_HELP:
			help();
			break;
		case USER_EXIT:
			std::cout << "Bye bye!" << std::endl;
			break;
		default:
			std::cout << "Invalid option" << std::endl;
		}
	} while (choice != 'X');
}
/*******************************************************
 * Function Name: login()
 * Purpose: compares login username and password with 
 * the ones provided. If matches, moves to MainMenu.
 * Else, shows a data exception error
 *******************************************************/
void LoginMenu::login()
{
	string _username, _password;
	int attempts = 3;

	while (attempts != 0)
	{
		cout << "Enter username: ";
		cin >> _username;
		cout << "Enter password: ";
		cin >> _password;
		try
		{
			if (_username == username && _password == password)
			{
				cout << "** Login successful" << endl;
				MainMenu mainMenu;
				mainMenu.activate();
			}
			else if (_username != username)
			{
				// Throw Exception if username doesnt match
				throw DataException(_username);
			}
			else if (_password != password)
			{
				// Throw a default exception if password doesnt match
				throw (_password);
			}
		}
		catch (DataException d)
		{
			cout << "Incorrect username. Try again." << endl;
		}
		catch (...)
		{
			cout << "Incorrect password. Try again." << endl;
		}
		--attempts;
	}
	cout << "Unable to login after three attempts";

}
/*******************************************************
 * Function Name: help()
 * Purpose: Provides guidance to the user in order to login
 * Parameter: none
 *******************************************************/
void LoginMenu::help()
{
	cout << "To access the educational platform you have to login into one of the existing accounts." << endl;
	cout << "Username: " << username << ". Password: " << password << endl;
}
