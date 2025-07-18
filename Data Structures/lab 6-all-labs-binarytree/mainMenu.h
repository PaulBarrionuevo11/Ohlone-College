#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <iostream>
#include "menu.h"

using namespace std;

/*******************************************************
 * Class Name: MainMenu
 * Purpose: Represents the main menu that inherits from the
 *          Menu class and provides additional functionality
 *          specific to user, contacts, courses, and grade book management.
 *******************************************************/
class MainMenu : public Menu {
    enum USER_OPTION {
        MANAGE_USER_ACCOUNT = '1',    // Option to manage user accounts
        MANAGE_CONTACTS = '2',       // Option to manage contacts
        MANAGE_COURSES = '3',        // Option to manage courses
        MANAGE_GRADE_BOOKS = '4',    // Option to manage grade books
        EXIT = 'X'                   // Option to exit the menu
    };

public:
    /*******************************************************
     * Function Name: MainMenu
     * Purpose: Constructor to initialize the MainMenu with
     *          predefined options.
     *******************************************************/
    MainMenu();

    /*******************************************************
     * Function Name: ~MainMenu
     * Purpose: Destructor for the MainMenu class.
     *******************************************************/
    ~MainMenu() {}

    /*******************************************************
     * Function Name: activate
     * Purpose: Activates the main menu, allowing the user
     *          to navigate through options.
     *******************************************************/
    void activate();

    /*******************************************************
     * Function Name: moveToUserAccounts
     * Purpose: Handles navigation to the user accounts management menu.
     *******************************************************/
    void moveToUserAccounts();

    /*******************************************************
     * Function Name: moveToContacts
     * Purpose: Handles navigation to the contacts management menu.
     *******************************************************/
    void moveToContacts();

    /*******************************************************
     * Function Name: moveToCourses
     * Purpose: Handles navigation to the courses management menu.
     *******************************************************/
    void moveToCourses();

    /*******************************************************
     * Function Name: moveToGradeBook
     * Purpose: Handles navigation to the grade book management menu.
     *******************************************************/
    void moveToGradeBook();

private:
    // Add private members or helper methods if necessary
};

#endif // MAIN_MENU_H
