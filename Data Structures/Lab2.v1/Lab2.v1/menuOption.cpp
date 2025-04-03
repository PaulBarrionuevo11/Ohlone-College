#include "menuOption.h"

MenuOption::MenuOption(char key, const std::string& title, const std::string& details)
    : key(key), title(title), details(details) {}

char MenuOption::getKey() const {
    return key;
}

string MenuOption::getTitle() const {
    return title;
}

string MenuOption::getDetails() const {
    return details;
}
