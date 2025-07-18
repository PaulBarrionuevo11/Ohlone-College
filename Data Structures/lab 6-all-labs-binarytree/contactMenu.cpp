#include <iostream>
#include <sstream>
#include "contactMenu.h"
#include "person.h"
#include "contactManager.h"

ContactMenu::ContactMenu() : Menu("Contact Menu")
{
    /*******************************************************
     * Function Name: ContactMenu
     * Purpose: Constructor for the ContactMenu class, which
     *          initializes the contact menu with various options
     *          and loads data from the file into the contact list.
     * Parameter: None
     * Return: None
     *******************************************************/
     // Add options to the user menu
    MenuOption op1('1', "List of contacts", "Show details");
    MenuOption op2('2', "View of contacts", "Show details");
    MenuOption op3('3', "Add new contact", "Show details");
    MenuOption op4('4', "Edit contact", "Show details");
    MenuOption op5('5', "Delete contact", "Show details");
    MenuOption op6('X', "Quit", "Show details");

    addOption(op1);
    addOption(op2);
    addOption(op3);
    addOption(op4);
    addOption(op5);
    addOption(op6);

    initData();
}

ContactMenu::~ContactMenu()
{
    /*******************************************************
     * Function Name: ~ContactMenu
     * Purpose: Destructor for the ContactMenu class. It saves
     *          data to the contact file and ensures that
     *          the input file is properly closed.
     * Parameter: None
     * Return: None
     *******************************************************/
    saveData();

    if (inFile.is_open()) {
        inFile.close();
    }

    cout << "User data saved successfully. Exiting User Menu." << endl;
}

void ContactMenu::showContactList()
{
    /*******************************************************
     * Function Name: showContactList
     * Purpose: Prompts the user to enter a field to sort
     *          the contact list by (e.g., id, name).
     * Parameter: None
     * Return: None
     *******************************************************/
    cout << "Enter field to sort by (e.g., id, firstName, lastName): ";
    contactList.sort();  // Calls quickSort internally based on the selected 

}

void ContactMenu::viewContact()
{
    /*******************************************************
     * Function Name: viewContact
     * Purpose: Displays the list of all contacts and their details
     *          such as id, name, and contact information.
     * Parameter: None
     * Return: None
     *******************************************************/
    cout << "id, first_name, middle_name, last_name, company_name, address, city, county, state, zip, phone1, phone2, email" << endl;
    contactList.print();
}

void ContactMenu::addContact()
{
    /*******************************************************
     * Function Name: addContact
     * Purpose: Collects details from the user to create a new
     *          contact and adds it to the contact list.
     * Parameter: None
     * Return: None
     *******************************************************/
    string id, firstName, middleName, lastName, company, address,
        city, county, state, zip, email, phone1, phone2;

    // If will be auto-generated
    cout << "**Enter the following information**" << endl;
    cout << "First name: ";
    cin >> firstName;
    cout << "Middle name: ";
    cin >> middleName;
    cout << "Last name: ";
    cin >> lastName;
    cout << "Company: ";
    cin >> company;
    cout << "Address: ";
    cin >> address;
    cout << "City: ";
    cin >> city;
    cout << "County: ";
    cin >> county;
    cout << "State: ";
    cin >> state;
    cout << "Zip code: ";
    cin >> zip;
    cout << "Phone number: ";
    cin >> phone1;
    cout << "Additional phone number: ";
    cin >> phone2;
    cout << "Email: ";
    cin >> email;

    Person p;
    p.setId(1000 + contactList.size() + 1);
    p.setFirstName(firstName);
    p.setMiddleName(middleName);
    p.setLastName(lastName);
    p.setCompany(company);
    p.setAddress(address);
    p.setCity(city);
    p.setCounty(county);
    p.setZip(zip);
    p.setState(state);
    p.setPhone1(phone1);
    p.setPhone2(phone2);
    p.setEmail(email);

    // Add person to contact list
    contactList.insert(p);
}

void ContactMenu::editContact()
{
    /*******************************************************
     * Function Name: editContact
     * Purpose: Allows the user to edit the details of an
     *          existing contact in the contact list.
     * Parameter: None
     * Return: None
     *******************************************************/
     // Prompt the user to enter the ID of the contact to edit
    int id;
    cout << "Enter the contact ID you want to edit: ";
    cin >> id;

    // Search for the contact in the contactList
    bool contactFound = false;
    for (int i = 0; i < contactList.size(); ++i) {
        if (contactList.at(i).getId() == id) {
            // Contact found
            contactFound = true;
            Person& contact = contactList.at(i);  // Reference to the contact for editing

            // Show current details and ask the user which fields to edit
            cout << "Editing contact with ID: " << id << endl;
            cout << "Current first name: " << contact.getFirstName() << endl;
            cout << "Enter new first name (or press Enter to keep it the same): ";
            string newFirstName;
            cin.ignore();  // Ignore any leftover newline character
            getline(cin, newFirstName);
            if (!newFirstName.empty()) {
                contact.setFirstName(newFirstName);
            }

            cout << "Current middle name: " << contact.getMiddleName() << endl;
            cout << "Enter new middle name (or press Enter to keep it the same): ";
            string newMiddleName;
            getline(cin, newMiddleName);
            if (!newMiddleName.empty()) {
                contact.setMiddleName(newMiddleName);
            }

            cout << "Current last name: " << contact.getLastName() << endl;
            cout << "Enter new last name (or press Enter to keep it the same): ";
            string newLastName;
            getline(cin, newLastName);
            if (!newLastName.empty()) {
                contact.setLastName(newLastName);
            }

            cout << "Current company: " << contact.getCompany() << endl;
            cout << "Enter new company (or press Enter to keep it the same): ";
            string newCompany;
            getline(cin, newCompany);
            if (!newCompany.empty()) {
                contact.setCompany(newCompany);
            }

            cout << "Current address: " << contact.getAddress() << endl;
            cout << "Enter new address (or press Enter to keep it the same): ";
            string newAddress;
            getline(cin, newAddress);
            if (!newAddress.empty()) {
                contact.setAddress(newAddress);
            }

            cout << "Current city: " << contact.getCity() << endl;
            cout << "Enter new city (or press Enter to keep it the same): ";
            string newCity;
            getline(cin, newCity);
            if (!newCity.empty()) {
                contact.setCity(newCity);
            }

            cout << "Current county: " << contact.getCounty() << endl;
            cout << "Enter new county (or press Enter to keep it the same): ";
            string newCounty;
            getline(cin, newCounty);
            if (!newCounty.empty()) {
                contact.setCounty(newCounty);
            }

            cout << "Current state: " << contact.getState() << endl;
            cout << "Enter new state (or press Enter to keep it the same): ";
            string newState;
            getline(cin, newState);
            if (!newState.empty()) {
                contact.setState(newState);
            }

            cout << "Current zip: " << contact.getZip() << endl;
            cout << "Enter new zip (or press Enter to keep it the same): ";
            string newZip;
            getline(cin, newZip);
            if (!newZip.empty()) {
                contact.setZip(newZip);
            }

            cout << "Current phone number 1: " << contact.getPhone1() << endl;
            cout << "Enter new phone number 1 (or press Enter to keep it the same): ";
            string newPhone1;
            getline(cin, newPhone1);
            if (!newPhone1.empty()) {
                contact.setPhone1(newPhone1);
            }

            cout << "Current phone number 2: " << contact.getPhone2() << endl;
            cout << "Enter new phone number 2 (or press Enter to keep it the same): ";
            string newPhone2;
            getline(cin, newPhone2);
            if (!newPhone2.empty()) {
                contact.setPhone2(newPhone2);
            }

            cout << "Current email: " << contact.getEmail() << endl;
            cout << "Enter new email (or press Enter to keep it the same): ";
            string newEmail;
            getline(cin, newEmail);
            if (!newEmail.empty()) {
                contact.setEmail(newEmail);
            }

            cout << "Contact updated successfully!" << endl;
            break;
        }
    }

    if (!contactFound) {
        cout << "Contact with ID " << id << " not found." << endl;
    }
}

void ContactMenu::deleteContact()
{
    /*******************************************************
     * Function Name: deleteContact
     * Purpose: Prompts the user for a contact ID and deletes
     *          the contact from the contact list if found.
     * Parameter: None
     * Return: None
     *******************************************************/
     // Prompt the user to enter the ID of the contact to delete
    int id;
    cout << "Enter the contact ID you want to delete: ";
    cin >> id;

    // Find the contact in the contactList
    bool contactFound = false;
    for (int i = 0; i < contactList.size(); ++i) {
        if (contactList.at(i).getId() == id) {
            // Contact found, remove it
            contactList.remove(contactList.at(i));
            contactFound = true;
            cout << "Contact with ID " << id << " has been deleted." << endl;
            break;
        }
    }

    if (!contactFound) {
        cout << "Contact with ID " << id << " not found." << endl;
    }
}

void ContactMenu::activate()
{
    /*******************************************************
     * Function Name: activate
     * Purpose: Main menu activation function. It handles user
     *          input and calls the appropriate functions for
     *          managing contacts.
     * Parameter: None
     * Return: None
     *******************************************************/
    char choice = 0;
    do {
        choice = getInput();
        switch (choice) {
        case CONTACT_LIST:
            showContactList();
            break;
        case CONTACT_VIEW:
            viewContact();
            break;
        case ADD_CONTACT:
            addContact();
            break;
        case EDIT_CONTACT:
            editContact();
            break;
        case DELETE_CONTACT:
            deleteContact();
            break;
        case USER_EXIT:
            cout << "Bye bye!" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
        }
    } while (choice != 'X');
}

void ContactMenu::initData()
{
    /*******************************************************
     * Function Name: initData
     * Purpose: Initializes contact data by reading from
     *          the contact data file and adding each contact
     *          to the contact list.
     * Parameter: None
     * Return: None
     *******************************************************/
    ifstream inFile(CONTACT_DATA);
    if (inFile.fail()) {
        cout << "Unable to open the file: " << CONTACT_DATA << endl;
        return;
    }
    string line;
    getline(inFile, line);  // Skip header row
    while (getline(inFile, line))
    {
        istringstream ss(line);
        string value;
        Person contact;

        getline(ss, value, ',');
        contact.setId(stoi(value));
        getline(ss, value, ',');
        contact.setFirstName(value);
        getline(ss, value, ',');
        contact.setMiddleName(value);
        getline(ss, value, ',');
        contact.setLastName(value);
        getline(ss, value, ',');
        contact.setCompany(value);
        getline(ss, value, ',');
        contact.setAddress(value);
        getline(ss, value, ',');
        contact.setCity(value);
        getline(ss, value, ',');
        contact.setCounty(value);
        getline(ss, value, ',');
        contact.setState(value);
        getline(ss, value, ',');
        contact.setZip(value);
        getline(ss, value, ',');
        contact.setPhone1(value);
        getline(ss, value, ',');
        contact.setPhone2(value);
        getline(ss, value, ',');
        contact.setEmail(value);
        getline(ss, value, ',');

        contactList.insert(contact);
    }
    inFile.close();
}

void ContactMenu::saveData()
{
    /*******************************************************
     * Function Name: saveData
     * Purpose: Saves the current contact list data to a file.
     *          Writes the contact data to a CSV file for
     *          persistent storage.
     * Parameter: None
     * Return: None
     *******************************************************/
    ofstream outFile(CONTACT_DATA);
    if (outFile.fail()) {
        cout << "Unable to open the file for writing: " << CONTACT_DATA << endl;
        return;
    }

    // Write the header row
    outFile << "id,first_name,middle_name,last_name,company_name,address,city,county,state,zip,phone1,phone2,email" << endl;

    // Iterate over the ContactList and write each contact's details
    for (int i = 0; i < contactList.size(); ++i) {
        const Person& contact = contactList.at(i);  // Access each contact from the ContactList

        outFile << contact.getId() << ","
            << contact.getFirstName() << ","
            << contact.getMiddleName() << ","
            << contact.getLastName() << ","
            << contact.getCompany() << ","
            << contact.getAddress() << ","
            << contact.getCity() << ","
            << contact.getCounty() << ","
            << contact.getState() << ","
            << contact.getZip() << ","
            << contact.getPhone1() << ","
            << contact.getPhone2() << ","
            << contact.getEmail() << endl;
    }

    outFile.close();
    cout << "Contact data saved successfully." << endl;
}
