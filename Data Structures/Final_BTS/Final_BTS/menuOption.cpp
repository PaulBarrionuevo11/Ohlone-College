#include <string>
#include <iostream>
#include "menuOption.h"

using namespace std;

/*******************************************************
 * Function Name: MenuOption
 * Purpose: Constructor to initialize a MenuOption with
 *          specified key, short name, and long name.
 * Parameters:
 *    key - the character key for the option
 *    shortName - a short description of the option
 *    longName - a detailed description of the option
 *******************************************************/
MenuOption::MenuOption(char key, string shortName, string longName) {
    setOption(key, shortName, longName);
}

/*******************************************************
 * Function Name: ~MenuOption
 * Purpose: Destructor for the MenuOption class.
 *******************************************************/
MenuOption::~MenuOption() {
    // Uncomment for debugging:
    // cout << "Test Destructor: " << shortName << endl;
}

/*******************************************************
 * Function Name: setOption
 * Purpose: Sets the attributes of the menu option.
 * Parameters:
 *    key - the character key for the option
 *    shortName - a short description of the option
 *    longName - a detailed description of the option
 *******************************************************/
void MenuOption::setOption(char key, string shortName, string longName) {
    this->key = key;
    this->shortName = shortName;
    this->longName = longName;
}

/*******************************************************
 * Function Name: getKey
 * Purpose: Retrieves the key of the menu option.
 * Return: The character key associated with the menu option.
 *******************************************************/
char MenuOption::getKey() {
    return key;
}

/*******************************************************
 * Function Name: getShortName
 * Purpose: Retrieves the short name of the menu option.
 * Return: The short description of the menu option.
 *******************************************************/
string MenuOption::getShortName() {
    return shortName;
}

/*******************************************************
 * Function Name: getLongName
 * Purpose: Retrieves the long name of the menu option.
 * Return: The detailed description of the menu option.
 *******************************************************/
string MenuOption::getLongName() {
    return longName;
}

/*******************************************************
 * Function Name: operator=
 * Purpose: Assigns the attributes of one MenuOption to another.
 * Parameter: option - a reference to the MenuOption to copy from
 * Return: A reference to this MenuOption object
 *******************************************************/
MenuOption& MenuOption::operator=(const MenuOption& option) {
    if (this != &option) {
        this->setOption(option.key, option.shortName, option.longName);
    }
    return *this;
}
