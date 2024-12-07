#ifndef LOGIN_MENU_H
#define LOGIN_MENU_H

#include <iostream>
#include <fstream>
#include "menu.h"
#include "user.h"
#include "Tree.h"

using namespace std;

class LoginMenu : public Menu
{
    enum USER_OPTION {
        USER_LOGIN = '1',
        USER_HELP = '2',
        USER_EXIT = 'X'
    };

public:
    LoginMenu();
    ~LoginMenu() {}
    void activate();
    void login();
    void help();

    User user;

private:
    /* In case you want to intialize menus with existing data */
    // vector<User> users;
    // ifstream inFile;
    // void initUserData(); 

    // Login username and password
    string username = "Paul";
    string password = "CS124";
};

#endif // !LOGIN_MENU_H
