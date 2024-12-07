#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include "menuOption.h"

using namespace std;

class Menu {

public:
	Menu(string name);
	~Menu();

	void addOption(MenuOption& option);
	/**
	 Displays the menu, with options numbered starting with 1,
	 and prompts the user for input. Repeats until a valid input
	 is supplied.
	 @return the number that the user supplied
	 */
	int getInput();


private:
	string name;
	vector<MenuOption*> options;

	MenuOption& getOption(char key);
	void display();
};

#endif