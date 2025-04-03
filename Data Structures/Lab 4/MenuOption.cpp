#include "menuOption.h"

/*******************************************************
 * Purpose: Constructor of class where parameters will
 * complete the details of the menu options
 *
 * @params key title and details
 *******************************************************/
MenuOption::MenuOption(char _key, const string& _title, const string& _details)
{
    key = _key;
    title = _title;
    details = _details;
}
/*******************************************************
 * Purpose: get key from the instantiation of the class
 *
 * @params none
 * @return key that will be passed from constructor
 *******************************************************/
char MenuOption::getKey() const {
    return key;
}
/*******************************************************
 * Purpose: get title from the instantiation of the class
 *
 * @params none
 * @return title that will be passed from constructor
 *******************************************************/
string MenuOption::getTitle() const {
    return title;
}
/*******************************************************
 * Purpose: get details from the instantiation of the class
 *
 * @params none
 * @return details that will be passed from constructor
 *******************************************************/
string MenuOption::getDetails() const {
    return details;
}