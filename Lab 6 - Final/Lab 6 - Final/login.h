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
    const string USERS_DATA = "C:/Users/pable/Documents/Ohlone/Data Structures/Downloads/users_data.csv";
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
    vector<User> users;
    ifstream inFile;
    /*void initUserData();*/
    Tree<Menu> menuTree; // The tree of menus
    string username = "Paul";
    string password = "CS124";
};

#endif // !LOGIN_MENU_H
