#ifndef MENU_OPTION_H
#define MENU_OPTION_H

#include <iostream>
using namespace std;

class MenuOption
{
private:
	char key;
	string title;
	string description;

public:
	MenuOption(char _key, string _title, string _description);
	// Getters
	char getKey() const;
	string getTitle() const;
	string getDescription() const;
	// Setters
	void setKey(char _key);
	void setTitle(string _title);
	void setDescription(char _description);

};
#endif // !MENU_OPTION_H
