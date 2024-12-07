#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <iostream>
#include "menu.h"

using namespace std;

class MainMenu : public Menu
{
    enum USER_OPTION {
        MANAGE_USER_ACCOUNT = '1',
        MANAGE_CONTACTS = '2',
        MANAGE_COURSES = '3',
        MANAGE_GRADE_BOOKS = '4',
        EXIT = 'X'
    };
public:
    MainMenu();
    ~MainMenu() {}
    void activate();
    void moveToUserAccounts();
    void moveToContacts();
    void moveToCourses();
    void moveToGradeBook();

private:

};

#endif // !MAIN_MENU_H