#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "menuOption.h"
#include <iostream>
using namespace std;

/*******************************************************
 * Purpose: Class managing the interaction of the menu options
 * 
 * @param protected attributes to pass down to derived class
 * like MenuOption and public Constructor and methods that the
 * program can manipulate when menu is instantiated
 * @note 
 *******************************************************/

class Menu {
protected:
    string title;
    vector<MenuOption> options;

public:
    Menu(const string& title);
    void addOption(const MenuOption& option);
    int getInput();
    void display() const;
};

#endif