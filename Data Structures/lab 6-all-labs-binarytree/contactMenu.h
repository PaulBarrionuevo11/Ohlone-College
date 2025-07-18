#ifndef CONTACTMENU_H
#define CONTACTMENU_H

#include <iostream>
#include <fstream>
#include "menu.h"
#include "person.h"
#include "contactManager.h"

using namespace std;

class ContactMenu : public Menu {

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

    /*******************************************************
     * Function Name: initData
     * Purpose: Initialize the contact list by loading data
     *          from the contact data file into the contact manager.
     * Parameter: None
     * Return: None
     *******************************************************/
    void initData();

    /*******************************************************
     * Function Name: saveData
     * Purpose: Save the current contact list data to the
     *          contact data file.
     * Parameter: None
     * Return: None
     *******************************************************/
    void saveData();

public:
    /*******************************************************
     * Function Name: ContactMenu
     * Purpose: Constructor to initialize the ContactMenu object.
     *          This initializes the menu options and loads
     *          contact data.
     * Parameter: None
     * Return: None
     *******************************************************/
    ContactMenu();

    /*******************************************************
     * Function Name: ~ContactMenu
     * Purpose: Destructor to clean up resources, save data
     *          to the file, and close the input file stream.
     * Parameter: None
     * Return: None
     *******************************************************/
    ~ContactMenu();

    /*******************************************************
     * Function Name: showContactList
     * Purpose: Displays the list of all contacts in the
     *          contact manager.
     * Parameter: None
     * Return: None
     *******************************************************/
    void showContactList();

    /*******************************************************
     * Function Name: viewContact
     * Purpose: Displays the details of a selected contact.
     * Parameter: None
     * Return: None
     *******************************************************/
    void viewContact();

    /*******************************************************
     * Function Name: addContact
     * Purpose: Allows the user to add a new contact to
     *          the contact list.
     * Parameter: None
     * Return: None
     *******************************************************/
    void addContact();

    /*******************************************************
     * Function Name: editContact
     * Purpose: Allows the user to edit the details of
     *          an existing contact.
     * Parameter: None
     * Return: None
     *******************************************************/
    void editContact();

    /*******************************************************
     * Function Name: deleteContact
     * Purpose: Allows the user to delete a contact from
     *          the contact list.
     * Parameter: None
     * Return: None
     *******************************************************/
    void deleteContact();

    /*******************************************************
     * Function Name: activate
     * Purpose: Activates the contact menu and handles
     *          user input to perform the appropriate
     *          actions for managing contacts.
     * Parameter: None
     * Return: None
     *******************************************************/
    void activate();

protected:
    /*******************************************************
     * Function Name: contactList
     * Purpose: A protected instance of ContactManager that
     *          manages the list of contacts.
     * Parameter: None
     * Return: None
     *******************************************************/
    ContactManager contactList;
};

#endif // CONTACTMENU_H
