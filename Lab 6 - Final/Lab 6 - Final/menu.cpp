#include <iostream>
#include "menu.h"
#include "menuOption.h"

using namespace std;

/*******************************************************
 * Function Name: Menu
 * Purpose: Constructor to initialize a Menu with a given name.
 * Parameter: name - the name of the menu
 *******************************************************/
Menu::Menu(string name) {
    this->name = name;
}

/*******************************************************
 * Function Name: ~Menu
 * Purpose: Destructor to clean up allocated memory for menu options.
 *******************************************************/
Menu::~Menu() {
    for (int i = 0; i < options.size(); i++) {
        delete options.at(i);
    }
}

/*******************************************************
 * Function Name: addOption
 * Purpose: Adds a MenuOption to the menu.
 * Parameter: option - a reference to a MenuOption to be added
 *******************************************************/
void Menu::addOption(MenuOption& option) {
    MenuOption* p = new MenuOption();
    *p = option;
    options.push_back(p);
}

/*******************************************************
 * Function Name: display
 * Purpose: Displays the menu options with their keys and short names.
 *******************************************************/
void Menu::display() {
    cout << "** " << name << " **" << endl;
    for (int i = 0; i < options.size(); i++) {
        MenuOption* option = options.at(i);
        cout << "\t" << static_cast<char>(option->getKey()) << ") " << option->getShortName() << endl;
    }
}

/*******************************************************
 * Function Name: getOption
 * Purpose: Retrieves a MenuOption by its key.
 * Parameter: key - the character key for the desired option
 * Return: A reference to the corresponding MenuOption
 *******************************************************/
MenuOption& Menu::getOption(char key) {
    for (int i = 0; i < options.size(); i++) {
        if (options.at(i)->getKey() == key) {
            return *options.at(i);
        }
    }
    // No return statement for non-existing key, 
    // consider adding error handling to address this.
}

/*******************************************************
 * Function Name: getInput
 * Purpose: Displays the menu, prompts the user for input, and
 *          repeats until a valid input is provided.
 * Return: The ASCII integer value of the selected key
 *******************************************************/
int Menu::getInput() {
    char input;
    bool valid = false;
    do {
        display();
        cout << "Select option: ";
        cin >> input;
        for (MenuOption* option : options) {
            if (option->getKey() == input) {
                cout << option->getLongName() << endl;
                valid = true;
                break;
            }
        }
        if (!valid) {
            cout << "\nPlease select a valid option." << endl << endl;
        }
    } while (!valid);
    return static_cast<int>(input);
}
