#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>
#include "menuOption.h"
#include <iostream>

using namespace std;

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
