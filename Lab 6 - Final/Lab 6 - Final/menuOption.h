#pragma once
#include <string>

using namespace std;

class MenuOption {
public:
	MenuOption() = default;
	MenuOption(char key, string shortName, string longName);
	~MenuOption();

	void setOption(char key, string shortName, string longName);
	char getKey();
	string getShortName();
	string getLongName();

	MenuOption& operator=(const MenuOption&);

protected:
	char key;
	string shortName;
	string longName;
};
