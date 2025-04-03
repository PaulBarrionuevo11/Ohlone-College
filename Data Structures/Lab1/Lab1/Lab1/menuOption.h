#ifndef MENU_OPTION_H
#define MENU_OPTION_H
#include <iostream>

using namespace std;

class MenuOption
{
public:
	/* Empty constructor, one with three arguments and destructor*/
	MenuOption(); 
	MenuOption(int key_, string shortName_, string longName_);
	~MenuOption();

	// Getters
	int getKey() const;
	string getShortName() const;
	string getLongName() const;

	// Setters
	void setKey(int key_);
	void setShortName(int shortName_);
	void setLongName(int longName_);
private:
	int key;		// Selected key from the console
	string shortName; // Display the user option
	string longName; // Description of the option
};
#endif // !MENU_OPTION_H
