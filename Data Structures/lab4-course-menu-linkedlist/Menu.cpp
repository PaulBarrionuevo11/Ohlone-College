#include "menu.h"

/*******************************************************
 * Purpose: Constructs a Menu object with the given title.
 * 
 * @param title - A string representing the title of the menu.
 *******************************************************/
Menu::Menu(const string& title) : title(title) {}

/*******************************************************
 * Purpose: Adds a MenuOption to the menu's list of options.
 * 
 * Parameter: option - A reference to a MenuOption object to be added.
 *******************************************************/
void Menu::addOption(const MenuOption& option) {
    options.push_back(option);
}
/*******************************************************
 * Purpose: Displays the menu title and read only list of menu
 * options to the console.
 * 
 *******************************************************/
void Menu::display() const {
    cout << "\n****** " << title << " ******" << endl;
    for (const auto& option : options) {
        cout << option.getKey() << ") " << option.getTitle() << endl;
    }
}
/*******************************************************
 * Purpose: Displays the menu and prompts the user to choose an option.
 *          Returns the key of the selected option if valid, or -1 if invalid.
 * Return: int - The key of the selected menu option, or -1 for invalid input.
 *******************************************************/
int Menu::getInput() {
    display();
    char choice;
    cout << "Choose an option: ";
    cin >> choice;

    for (const auto& option : options) {
        if (option.getKey() == choice) {
            return choice;
        }
    }

    return -1; // Invalid input
}
