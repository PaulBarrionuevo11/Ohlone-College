#ifndef CONTACTMENU_H
#define CONTACTMENU_H

#include <iostream>
#include <fstream>
#include "MenuOption.h"
#include "Menu.h"
#include "Person.h"
#include "ContactList.h"

using namespace std;

class ContactMenu : public Menu{

string CONTACT_DATA = "C:/Users/pable/Documents/Ohlone/Data Structures/Downloads/contacts_data.csv";

enum USER_OPTION
{
    CONTACT_LIST = '1',
    CONTACT_VIEW = '2',
    ADD_CONTACT = '3',
    EDIT_CONTACT = '4',
    DELETE_CONTACT = '5',
    USER_EXIT = 'X'
};
private:
    ifstream inFile;

    void initContactData();
    void saveData();
public:
    ContactMenu();
    ~ContactMenu();
    void showContactList();
    void viewContact();
    void addContact();
    void editContact();
    void deleteContact();

    void activate();  
protected:
    ContactList contactList;
};

#endif !CONTACTMENU_H
