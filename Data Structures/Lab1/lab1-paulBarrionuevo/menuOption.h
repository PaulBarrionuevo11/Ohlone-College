#ifndef MENU_OPTION_H
#define MENU_OPTION_H
#include <iostream>

using namespace std;

class MenuOption : public Menu
{
public:
	/* Empty constructor, one with three arguments and destructor*/
	MenuOption(); 
	MenuOption(char _key, string _shortName, string _longName);
	~MenuOption();
	// Getters
	char getKey() const;
	string getShortName() const;
	string getLongName() const;
	// Setters
	void setKey(char key_);
	void setShortName(int _shortName);
	void setLongName(int _longName);

private:
	char key;		// Selected key from the console
	string shortName; // Display the user option
	string longName; // Description of the option
};
#endif // !MENU_OPTION_H
