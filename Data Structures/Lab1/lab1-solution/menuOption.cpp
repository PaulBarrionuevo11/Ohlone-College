#include <string>
#include "menuOption.h"

using namespace std;

MenuOption::MenuOption(char key, string shortName, string longName) {
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
};