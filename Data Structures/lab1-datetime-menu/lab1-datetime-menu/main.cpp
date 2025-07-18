/*******************************************************
 * Program Name: Date time Menu Lab 1
 * Author: Paul Barrionuevo
 * Date: 9/14/2024
 * Description: Menu with multiple options to select
 * between date, time, date time and system clock
 *******************************************************/

#include <iostream>
#include "time.h"
#include "date.h"
#include "dateTime.h"
#include "menu.h"
#include "menuOption.h"

using namespace std;

int main()
{
    Menu m("User Menu");    // Menu instance with one param that describes the menu

    /* MenuOption instance with three params*/
    MenuOption op1('1', "Show date", "Show month:date:year");
    MenuOption op2('2', "Show time", "Show hour:minute:second");
    MenuOption op3('3', "Show datetime", "Show date in month:date:year and time in hour:minute:second");
    MenuOption op4('4', "Show time now", "Show systems time");
    MenuOption op5('X', "Exit", "Exit program, bye!");

    /* Method adding the MenuOption on the Menu class*/
    m.addItem(op1);
    m.addItem(op2);
    m.addItem(op3);
    m.addItem(op4);
    m.addItem(op5);

    // Method displaying all the menu options
    m.displayOptions();

    // Display Menu Options. Starts menu function
    m.getOption();

    return 0;
}


