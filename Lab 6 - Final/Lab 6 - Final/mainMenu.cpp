#include "mainMenu.h"
#include "tree.h"
#include "userMenu.h"
#include "courseMenu.h"
#include "contactMenu.h"

/*******************************************************
 * Function Name: MainMenu
 * Purpose: Constructor for the MainMenu class. Initializes
 *          the main menu with predefined options and activates it.
 *******************************************************/
MainMenu::MainMenu() : Menu("** Main Menu **") {
    MenuOption op1('1', "Manage User Accounts", "Description");
    MenuOption op2('2', "Manage Contacts", "Description");
    MenuOption op3('3', "Manage Courses", "Description");
    MenuOption op4('4', "Manage Grade Book", "Description");
    MenuOption opX('X', "Exit Program", "Description");

    addOption(op1);
    addOption(op2);
    addOption(op3);
    addOption(op4);
    addOption(opX);

    activate();
}

/*******************************************************
 * Function Name: activate
 * Purpose: Activates the main menu, displaying options and
 *          handling user input to navigate to appropriate menus.
 *******************************************************/
void MainMenu::activate() {
    char choice = 0;
    do {
        choice = getInput();
        switch (choice) {
        case MANAGE_USER_ACCOUNT:
            moveToUserAccounts();
            break;
        case MANAGE_CONTACTS:
            moveToContacts();
            break;
        case MANAGE_COURSES:
            moveToCourses();
            break;
        case MANAGE_GRADE_BOOKS:
            moveToGradeBook();
            break;
        case EXIT:
            cout << "Bye bye!" << endl;
            exit(0); // Exit the program
        default:
            cout << "Invalid option" << endl;
        }
    } while (choice != 'X');
}

/*******************************************************
 * Function Name: moveToUserAccounts
 * Purpose: Transitions to the User Accounts management menu.
 *******************************************************/
void MainMenu::moveToUserAccounts() {
    UserMenu accountMenu;
    accountMenu.activate();
}

/*******************************************************
 * Function Name: moveToContacts
 * Purpose: Transitions to the Contacts management menu.
 *******************************************************/
void MainMenu::moveToContacts() {
    ContactMenu contactMenu;
    contactMenu.activate();
}

/*******************************************************
 * Function Name: moveToCourses
 * Purpose: Transitions to the Courses management menu.
 *******************************************************/
void MainMenu::moveToCourses() {
    CourseMenu courseMenu;
    courseMenu.activate();
}

/*******************************************************
 * Function Name: moveToGradeBook
 * Purpose: Placeholder for transitioning to the Grade Book
 *          management menu. (Not yet implemented)
 *******************************************************/
void MainMenu::moveToGradeBook() {
    // Grade Book functionality not yet implemented
}
