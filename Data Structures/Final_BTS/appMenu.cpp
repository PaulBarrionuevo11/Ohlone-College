#include "appMenu.h"
#include "iomanip"

/*******************************************************
 * Class Name: AppMenu
 * Purpose: Manages a menu interface for interacting with
 *          contact data, including operations such as
 *          displaying data in order and searching.
 *******************************************************/

 // Constructor: Initializes the menu with predefined options
AppMenu::AppMenu() : Menu("Grade Menu")
{
    // MenuOption: Represents a single menu choice.
    MenuOption op1('1', "Show in order", "Show details"); // Option to display all contacts in order
    MenuOption op2('2', "Search", "Show details");        // Option to search for a specific contact
    MenuOption op3('X', "Quit", "Show details");          // Option to quit the application

    // Add options to the menu
    addOption(op1);
    addOption(op2);
    addOption(op3);

    // Initialize the application by loading contact data
    initialize();
}

// Destructor: Cleans up resources used by the menu
AppMenu::~AppMenu()
{
}

/*******************************************************
 * Function Name: initialize
 * Purpose: Reads contact data from a file and stores it in
 *          the appManager for later use.
 *******************************************************/
void AppMenu::initialize()
{
    // Open the file containing contact data
    ifstream inFile(CONTCTS_DATA);
    if (!inFile.is_open()) {
        cerr << "Failed to open file: " << CONTCTS_DATA << endl;
        return;
    }

    // Read the file line by line, skipping the header
    string line;
    getline(inFile, line); // Skip header
    while (getline(inFile, line))
    {
        istringstream ss(line); // Create a stream for parsing a line
        string value;
        Contact contact;

        // Extract values and set them in the Contact object
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

        // Add the contact to the appManager
        appManager.insert(contact);
    }
    inFile.close();
}

/*******************************************************
 * Function Name: activate
 * Purpose: Activates the menu, allowing users to interact
 *          with the application and choose options.
 *******************************************************/
void AppMenu::activate()
{
    char choice = 0;
    do {
        // Get the user's menu choice
        choice = getInput();
        switch (choice) {
        case SHOW_INORDER: // Option to show contacts in order
            showInOrder();
            break;
        case SEARCH: // Option to search for a contact
            showSearch();
            break;
        case EXIT: // Option to exit the application
            cout << "Bye bye!" << endl;
            exit(0);
            break;
        default: // Handle invalid options
            cout << "Invalid option" << endl;
        }
    } while (choice != 'X');
}

/*******************************************************
 * Function Name: showSearch
 * Purpose: Allows the user to search for a contact by ID.
 *******************************************************/
void AppMenu::showSearch()
{
    string value;
    cout << "Enter the First Name of the contact you are looking for: ";
    cin >> value;

    // Search for the contact and display the result
    bool search_found = appManager.search(value);
    if (search_found)
        return;
    else
        cout << "Element not found" << endl;
}

/*******************************************************
 * Function Name: showInOrder
 * Purpose: Displays all contacts in sorted order with a
 *          well-formatted table layout.
 *******************************************************/
void AppMenu::showInOrder() {
    // Print column headers with adjusted widths for readability
    cout << std::left
        << setw(12) << "FIRST NAME"
        << setw(15) << "MIDDLE NAME"
        << setw(15) << "LAST NAME"
        << setw(20) << "COMPANY"
        << setw(25) << "ADDRESS"
        << setw(15) << "CITY"
        << setw(15) << "COUNTY"
        << setw(10) << "STATE"
        << setw(8) << "ZIP"
        << setw(15) << "PHONE1"
        << setw(15) << "PHONE2"
        << setw(25) << "EMAIL"
        << endl;

    // Print all contacts from the appManager
    appManager.print();
}

// void GradeMenu::printOnlyParent()
// {
//     // Placeholder for additional functionality
// }
