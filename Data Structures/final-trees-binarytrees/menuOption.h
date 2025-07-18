#pragma once
#include <string>

using namespace std;

/*******************************************************
 * Class Name: MenuOption
 * Purpose: Represents a single menu option with a key,
 *          short name, and long name.
 *******************************************************/
class MenuOption {
public:
    /*******************************************************
     * Function Name: MenuOption
     * Purpose: Default constructor for the MenuOption class.
     *******************************************************/
    MenuOption() = default;

    /*******************************************************
     * Function Name: MenuOption
     * Purpose: Constructs a MenuOption with specified values.
     * Parameters:
     *    key - the character key for the option
     *    shortName - a short description of the option
     *    longName - a detailed description of the option
     *******************************************************/
    MenuOption(char key, string shortName, string longName);

    /*******************************************************
     * Function Name: ~MenuOption
     * Purpose: Destructor to clean up resources for the MenuOption class.
     *******************************************************/
    ~MenuOption();

    /*******************************************************
     * Function Name: setOption
     * Purpose: Sets the attributes of a menu option.
     * Parameters:
     *    key - the character key for the option
     *    shortName - a short description of the option
     *    longName - a detailed description of the option
     *******************************************************/
    void setOption(char key, string shortName, string longName);

    /*******************************************************
     * Function Name: getKey
     * Purpose: Retrieves the key of the menu option.
     * Return: The character key associated with the menu option.
     *******************************************************/
    char getKey();

    /*******************************************************
     * Function Name: getShortName
     * Purpose: Retrieves the short name of the menu option.
     * Return: The short description of the menu option.
     *******************************************************/
    string getShortName();

    /*******************************************************
     * Function Name: getLongName
     * Purpose: Retrieves the long name of the menu option.
     * Return: The detailed description of the menu option.
     *******************************************************/
    string getLongName();

    /*******************************************************
     * Function Name: operator=
     * Purpose: Assigns values from another MenuOption to this one.
     * Parameter:
     *    A reference to the MenuOption to copy from.
     * Return: A reference to this MenuOption object.
     *******************************************************/
    MenuOption& operator=(const MenuOption&);

protected:
    char key;            // Character key for the menu option
    string shortName;     // Short description of the menu option
    string longName;      // Detailed description of the menu option
};
