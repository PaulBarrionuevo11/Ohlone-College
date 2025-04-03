#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "menuOption.h"
#include <iostream>

using namespace std;

class Menu
{
private:
	string title;
	vector<MenuOption> options;

public:
	Menu(const string& _title);
	void addOption(const MenuOption& _option);
	int getInput();
	void display() const;


};
#endif // !MENU_H
