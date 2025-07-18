#ifndef MENUOPTION_H
#define MENUOPTION_H

#include <string>
#include <iostream>

using namespace std;

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