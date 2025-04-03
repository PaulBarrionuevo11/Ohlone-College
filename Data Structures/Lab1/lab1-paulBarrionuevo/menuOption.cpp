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
MenuOption::MenuOption(char _key, string _shortName, string _longName)
{
	this->key = _key;
	this->shortName = _shortName;
	this->longName = _longName;
}
/*******************************************************
 * Function Name: MenuOption Destructor
 * Purpose: Destroys the constructor of class MenuOption
 *******************************************************/
MenuOption::~MenuOption()
{
}
/*******************************************************
 * Function Name: getKey()
 * Purpose: Gets key for menu
 * Return: Class private attribute
 *******************************************************/
char MenuOption::getKey() const
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
void MenuOption::setKey(char _key)
{
	this->key = _key;
}
/*******************************************************
 * Function Name: setShortName()
 * Purpose: Sets the short name to class attribute
 * Parameter: shortName_ short name in menu option
 *******************************************************/
void MenuOption::setShortName(int _shortName)
{
	this->shortName = _shortName;
}
/*******************************************************
 * Function Name: setLongName()
 * Purpose: Sets the long name to class attribute
 * Parameter: longName_ long name in menu option
 *******************************************************/
void MenuOption::setLongName(int _longName)
{
	this->longName = _longName;
}