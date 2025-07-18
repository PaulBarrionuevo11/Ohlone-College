#ifndef MENUOPTION_H
#define MENUOPTION_H

#include <string>
#include <iostream>
using namespace std;

/*******************************************************
 * Purpose: attributes added as Menu Options
 *
 * @param public methods to get values passed on the 
 * instantiation of the class.
 * 
 * @note
 *******************************************************/

class MenuOption {
private:
    char key;
    string title;
    string details;

public:
    MenuOption(char key, const string& title, const string& details);
    char getKey() const;
    string getTitle() const;
    string getDetails() const;
};

#endif