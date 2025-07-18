#ifndef MENU_H
#define MENU_H

/*******************************************************
 * Class Name: Menu
 * Purpose: To represent a menu with multiple options
 *          that can be displayed to the user for selection.
 *******************************************************/

#include <string>
#include <vector>
#include "menuOption.h"

using namespace std;

class Menu {

public:
    /*******************************************************
     * Function Name: Menu
     * Purpose: Constructor to initialize a Menu with a given name.
     * Parameter: name - the name of the menu
     *******************************************************/
    Menu(string name);

    /*******************************************************
     * Function Name: ~Menu
     * Purpose: Destructor to clean up resources for the Menu class.
     *******************************************************/
    ~Menu();

    /*******************************************************
     * Function Name: addOption
     * Purpose: Adds an option to the menu.
     * Parameter: option - a reference to a MenuOption to be added
     *******************************************************/
    void addOption(MenuOption& option);

    /*******************************************************
     * Function Name: getInput
     * Purpose: Displays the menu, prompts the user for input,
     *          and ensures a valid input is provided.
     * Return: The number that the user supplied
     *******************************************************/
    int getInput();

private:
    string name;                       // Name of the menu
    vector<MenuOption*> options;       // List of menu options

    /*******************************************************
     * Function Name: getOption
     * Purpose: Retrieves a menu option based on the provided key.
     * Parameter: key - the key associated with the desired option
     * Return: A reference to the corresponding MenuOption
     *******************************************************/
    MenuOption& getOption(char key);

    /*******************************************************
     * Function Name: display
     * Purpose: Displays the menu options to the user.
     *******************************************************/
    void display();
};

#endif
