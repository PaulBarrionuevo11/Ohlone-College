#include <string>
#include <iostream>
#include "menuOption.h"

using namespace std;

MenuOption::MenuOption(char key, string shortName, string longName) {
	setOption(key, shortName, longName);
}

MenuOption::~MenuOption() {
	//cout << "Test Destructor: " << shortName << endl;
}

void MenuOption::setOption(char key, string shortName, string longName) {
	this->key = key;
	this->shortName = shortName;
	this->longName = longName;
}
char MenuOption::getKey() {
	return key;
}

string MenuOption::getShortName() {
	return shortName;
}

string MenuOption::getLongName() {
	return longName;
}

// Operator overloading - assignment, ex x = y
MenuOption& MenuOption::operator=(const MenuOption& option) {
	if (this != &option) {
		this->setOption(option.key, option.shortName, option.longName);
	}
	return *this;
}