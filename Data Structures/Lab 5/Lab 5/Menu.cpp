#include "Menu.h"

Menu::Menu(const string& _title)
{
	title = _title;
}
void Menu::addOption(const MenuOption& _option)
{
	options.push_back(_option);
}
void Menu::display() const
{
    cout << "\n****** " << title << " ******" << endl;
    for (const auto& option : options) {
        cout << option.getKey() << ") " << option.getTitle() << endl;
    }
}
int Menu::getInput()
{
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
