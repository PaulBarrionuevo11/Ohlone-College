#ifndef USERMENU_H
#define USERMENU_H

#include "menu.h"
#include "user.h" 
#include <vector>
#include <fstream>

class UserMenu : public Menu {
    const string USERS_DATA = "C:/Users/pable/Documents/Ohlone/Data Structures/Downloads/users_data.csv";
    enum USER_OPTION {
        USER_CREATE = '1',
        USER_LOGIN = '2',
        USER_LOGOUT = '3',
        USER_REMOVE = '4',
        USER_RESET = '5',
        USER_HELP = '6',
        USER_EXIT = 'X'
    };
private:
    vector<User> users;
    ifstream inFile;
    void initUserData();
    void saveData();

public:
    UserMenu();
    ~UserMenu();
    void activate();
    void create();
    void login();
    void logout();
    void remove();
    void reset();
    void help();

    // Getters/Setters for Users
    User& getUser(int id);
    User user;
    std::vector<User> getUsers() const;
    void setUser(const User& newUser);
    DateTime parseDateTime(const string& dateTimeStr);

};

#endif
