#include "MenuOption.h"

MenuOption::MenuOption(char _key, string _title, string _description)
{
	key = _key;
	title = _title;
	description = _description;
}
// Getters
char MenuOption::getKey() const
{
	return key;
}
string MenuOption::getTitle() const
{
	return title;
}
string MenuOption::getDescription() const
{
	return description;
}
// Setters
void MenuOption::setKey(char _key)
{
	key = _key;
}
void MenuOption::setTitle(string _title)
{
	title = _title;
}
void MenuOption::setDescription(char _description)
{
	description = _description;
}