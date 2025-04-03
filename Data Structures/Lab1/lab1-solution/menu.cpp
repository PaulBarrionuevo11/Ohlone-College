#include <iostream>
#include "menu.h"
#include "menuOption.h"

using namespace std;

Menu::Menu(string name) {
	this->name = name;
}
void Menu::addOption(MenuOption& option) {
	options.push_back(option);
}

void Menu::display() {
	cout << "***** " << name << " *****" << endl;
	for (int i = 0; i < options.size(); i++) {
		MenuOption& option = options.at(i);
		cout << "\t" << static_cast<char>(option.getKey()) << ") " << option.getShortName() << endl;
	}
}

MenuOption& Menu::getOption(char key) {
	for (int i = 0; i < options.size(); i++) {
		if (options.at(i).getKey() == key) {
			return options.at(i);
		}
	}
}

int Menu::getInput() {
	char input;
	bool valid = false;
	do {
		display();
		cout << "Select option: ";
		cin >> input;
		for (MenuOption option : options) {
			if (option.getKey() == input) {
				cout << option.getLongName() << endl;
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