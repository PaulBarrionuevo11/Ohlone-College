#ifndef USER_MENU_H
#define USER_MENU_H

#include <fstream>
#include <vector>
#include "menu.h"
#include "user.h"

using namespace std;

const string USERS_DATA = "C:/Users/pable/Documents/Github/Ohlone/Data Structures/Downloads/users_data.csv";

/*******************************************************
 * Enum Name: USER_OPTION
 * Purpose: Enumerates the available user menu options.
 *******************************************************/
enum USER_OPTION {
    USER_CREATE = '1',  // Option to create a new user
    USER_LOGIN = '2',   // Option to log in an existing user
    USER_LOGOUT = '3',  // Option to log out the current user
    USER_REMOVE = '4',  // Option to remove a user
    USER_RESET = '5',   // Option to reset user account settings
    USER_HELP = '6',    // Option to display help instructions
    USER_EXIT = 'X'     // Option to exit the user menu
};

/*******************************************************
 * Class Name: UserMenu
 * Purpose: Represents the menu for user account management.
 *          Allows login, logout, user creation, removal,
 *          and account resetting.
 *******************************************************/
class UserMenu : public Menu {
public:
    /*******************************************************
     * Function Name: UserMenu
     * Purpose: Constructor to initialize the UserMenu.
     *******************************************************/
    UserMenu();

    /*******************************************************
     * Function Name: ~UserMenu
     * Purpose: Destructor for the UserMenu class.
     *******************************************************/
    ~UserMenu();

    User user; // Represents the currently logged-in user

    /*******************************************************
     * Function Name: activate
     * Purpose: Activates the user menu, displaying options and
     *          handling user input to manage accounts.
     *******************************************************/
    void activate();

    /*******************************************************
     * Function Name: login
     * Purpose: Attempts to log in a user with up to 3 retries
     *          for invalid credentials. Updates the system
     *          datetime on success.
     * Return: True if login is successful; false otherwise.
     *******************************************************/
    bool login();

    /*******************************************************
     * Function Name: logout
     * Purpose: Logs out the current user, updates the logout
     *          datetime, and saves user data to the CSV file.
     *******************************************************/
    bool logout();

    /*******************************************************
     * Function Name: create
     * Purpose: Creates a new user and updates the list of users.
     *******************************************************/
    void create();

    /*******************************************************
     * Function Name: remove
     * Purpose: Removes an existing user from the list.
     *******************************************************/
    void remove();

    /*******************************************************
     * Function Name: reset
     * Purpose: Resets account details, such as passwords.
     *          Only accessible to the admin user.
     *******************************************************/
    void reset();

    /*******************************************************
     * Function Name: help
     * Purpose: Displays instructions on how to use the application.
     *******************************************************/
    void help();

private:
    fstream inFile;        // File stream for reading user data
    vector<User> users;    // List of available users

    /*******************************************************
     * Function Name: doLogin
     * Purpose: Internal method to perform login operations
     *          for a specific user.
     * Parameter: user - reference to the user attempting login
     * Return: True if login is successful; false otherwise.
     *******************************************************/
    bool doLogin(User&);
    /*******************************************************
     * Function Name: doLogOut
     * Purpose: Internal method to perform logout operations
     *          for a specific user.
     * Parameter: user - reference to the user attempting logout
     * Return: True if logout is successful; false otherwise.
     *******************************************************/
    bool doLogOut(User&);
    /*******************************************************
     * Function Name: initData
     * Purpose: Reads user data from the CSV file and populates
     *          the list of users.
     *******************************************************/
    void initData();

    /*******************************************************
     * Function Name: saveData
     * Purpose: Saves the current list of users to the CSV file.
     *******************************************************/
    void saveData();
};

#endif // USER_MENU_H
