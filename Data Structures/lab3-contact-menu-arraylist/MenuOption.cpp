#include "menuOption.h"

MenuOption::MenuOption(char _key, const string& _title, const string& _details)
{
    key = _key;
    title = _title;
    details = _details;
}

char MenuOption::getKey() const {
    return key;
}

string MenuOption::getTitle() const {
    return title;
}

string MenuOption::getDetails() const {
    return details;
}