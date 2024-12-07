#include "mainMenu.h"
#include "tree.h"
#include "userMenu.h"
#include "courseMenu.h"
#include "contactMenu.h"


MainMenu::MainMenu() :Menu("Main Menu")
{

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

void MainMenu::activate()
{
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
			exit(0);  // Exit the program
		default:
			cout << "Invalid option" << endl;
		}
	} while (choice != 'X');
}
void MainMenu::moveToUserAccounts()
{
	UserMenu accountMenu;
	accountMenu.activate();
}
void MainMenu::moveToContacts()
{
	ContactMenu contactMenu;
	contactMenu.activate();
}
void MainMenu::moveToCourses()
{
	CourseMenu courseMenu;
	courseMenu.activate();

}
void MainMenu::moveToGradeBook()
{

}
