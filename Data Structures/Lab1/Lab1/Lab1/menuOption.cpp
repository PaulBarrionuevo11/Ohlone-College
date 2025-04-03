#include "menuOption.h"
#include <iostream>

using namespace std;

/*******************************************************
 * Function Name: MenuOption Constructor
 * Purpose: Builds an empty constructor of the class
 *******************************************************/
MenuOption::MenuOption()
{
}
/*******************************************************
 * Function Name: MenuOption Constructor
 * Purpose: Builds a constructor with three arguments
 *******************************************************/
MenuOption::MenuOption(int key_, string shortName_, string longName_)
{
	this->key = key_;
	this->shortName = shortName_;
	this->longName = longName_;
}
/*******************************************************
 * Function Name: MenuOption Destructor
 * Purpose: Destroys the constructor of class MenuOption
 *******************************************************/
MenuOption::~MenuOption()
{
	cout << "Test destruct " << shortName << endl;
}

/*******************************************************
 * Function Name: getKey()
 * Purpose: Gets key for menu
 * Return: Class private attribute
 *******************************************************/
int MenuOption::getKey() const
{
	return this->key;
}
/*******************************************************
 * Function Name: getShortName()
 * Purpose: Gets short name for menu
 * Return: Class private attribute
 *******************************************************/
string MenuOption::getShortName() const
{
	return this->shortName;
}
/*******************************************************
 * Function Name: getLongName()
 * Purpose: Gets long name for menu
 * Return: Class private attribute
 *******************************************************/
string MenuOption::getLongName() const
{
	return this->longName;
}
/*******************************************************
 * Function Name: setKey()
 * Purpose: Sets the key to class attribute
 * Parameter: key_ key in menu option
 *******************************************************/
void MenuOption::setKey(int key_)
{
	this->key = key_;
}
/*******************************************************
 * Function Name: setShortName()
 * Purpose: Sets the short name to class attribute
 * Parameter: shortName_ short name in menu option
 *******************************************************/
void MenuOption::setShortName(int shortName_)
{
	this->shortName = shortName_;
}
/*******************************************************
 * Function Name: setLongName()
 * Purpose: Sets the long name to class attribute
 * Parameter: longName_ long name in menu option
 *******************************************************/
void MenuOption::setLongName(int longName_)
{
	this->longName = longName_;
}