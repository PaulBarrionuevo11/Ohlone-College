#include "userMenu.h"
#include "login.h"
#include "dataException.h"
#include "mainMenu.h"
#include <sstream>


LoginMenu::LoginMenu() : Menu("Login Menu")
{
	//cout << "Enter your account";
	MenuOption op1('1', "Enter your account to login", "Description");
	MenuOption op2('2', "Get Help", "Description");
	MenuOption op3('X', "Exit", "Description");

	addOption(op1);
	addOption(op2);
	addOption(op3);

	//initUserData();

}
//LoginMenu::~LoginMenu()
//{
//	if (inFile.is_open())
//	{
//		inFile.close();
//	}
//}
//void LoginMenu::initUserData()
//{
//	ifstream inFile(USERS_DATA); // Assuming USERS_DATA points to users.csv
//	if (inFile.fail()) {
//		cout << "Unable to open the file: " << USERS_DATA << endl;
//		return;
//	}
//	string line;
//	getline(inFile, line); // Skip the header line
//	while (getline(inFile, line)) {
//		istringstream ss(line);
//		string text;
//
//		getline(ss, text, ',');
//		user.setId(stoi(text));
//		getline(ss, text, ',');
//		user.setUsername(text);
//		getline(ss, text, ',');
//		user.setPassword(text);
//		getline(ss, text, ',');
//		user.setRole(stoi(text));
//		getline(ss, text, ',');
//		user.setEmail(text);
//		getline(ss, text, ',');
//		users.push_back(user);
//	}
//	inFile.close();
//	activate();
//}

void LoginMenu::activate()
{
	//NodeTree<Menu>* currentNode = menuTree.getRoot();
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
				if (inFile.is_open())
				{
					inFile.close();
				}
				MainMenu mainMenu;
				mainMenu.activate();
				// TODO: Activate Main menu
			}
			else if (_username != username)
			{
				throw DataException(_username);
			}
			else if (_password != password)
			{
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
void LoginMenu::help()
{
	cout << "To access the educational platform you have to login into one of the existing accounts." << endl;
	cout << "Username: " << username << ". Password: " << password << endl;
	//for (auto user : users)
	//{
	//	cout << " - " << user.getUsername() << endl;
	//}
}
