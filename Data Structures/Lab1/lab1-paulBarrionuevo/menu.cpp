#include <iostream>
#include <string>
#include <vector>
#include "menu.h"
#include "menuOption.h"
#include "date.h"
#include "time.h"
#include "dateTime.h"

using namespace std;

/*******************************************************
 * Function Name: Menu Constructor
 * Purpose: Builds a constructor passing a menu name
 *******************************************************/
Menu::Menu(string menuName_)
{
    this->menuName = menuName_;
}
/*******************************************************
 * Function Name: addItem()
 * Purpose: Accepts a MenuOption object and adds it to vector of MenuOption type
 *******************************************************/
void Menu::addItem(MenuOption& _option)
{
    options.push_back(_option);
}
/*******************************************************
 * Function Name: displayOptions()
 * Purpose: Displays each individual object in the vector
 * Return: Console out the key and short name from the object
 *******************************************************/
void Menu::displayOptions() const
{
    cout << "****** " << menuName << " - Datetime ******" << endl;
    for (int i = 0; i < options.size(); i ++) 
    {
        cout << options[i].getKey() << ") " << options[i].getShortName() << endl;
    }
}
/*******************************************************
 * Function Name: getOption()
 * Purpose: Displays the output after selecting one of the options
 * Return: Console out:
 * 1) The command that was selected
 * 2) The long name 
 * 3) The value that correspond to the menu option. ex: time or date
 *******************************************************/
char Menu::getOption() const
{
    Date date;
    Time time;
    DateTime datetime;

    char input;
    do
    {
        //displayOption();
        cin >> input;
        if (input == '1' || input == 'a')
        {
            cout << "Command: " << input << endl;
            cout << options[0].getLongName() << endl;
            cout << date.toString() << endl;
        }
        else if (input == '2' || input == 'b')
        {
            cout << "Command: " << input << endl;
            cout << options[1].getLongName() << endl;
            cout << time.toString() << endl;
        }
        else if (input == '3' || input == 'c')
        {
            cout << "Command: " << input << endl;
            cout << options[2].getLongName() << endl;
            cout << datetime.toString() << endl;

        }
        else if (input == '4' || input == 'd')
        {
            cout << "Command: " << input << endl;
            cout << options[3].getLongName() << endl;
            //  << time.getSystemTime() << endl;
            
        }
        else if (input == 'X' || input == 'x')
        {
            cout << "Command: " << input << endl;
            cout << options[4].getLongName() << endl;
            break;
        }
        else
        {
            cout << "Try again" << endl;
        }
    } while (input < 1 || input > options.size());
    return input;
}
