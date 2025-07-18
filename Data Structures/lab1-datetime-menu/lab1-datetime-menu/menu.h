#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "menuOption.h"

using namespace std;

class Menu
{
public:
    // Builds a constructor passing a menu name
    Menu(string _menuName);
    // Adds an option to the end of this menu.
    void addItem(MenuOption& _option);
    // Get option selected from the console
    char getOption() const;
    // Displays the options created and stored in the array
    void displayOptions() const;

private:
    string menuName;
    vector<MenuOption> options;
};
#endif // !MENU_H