#include "userMenu.h"
#include <iostream>
#include <sstream>
#include "dateTime.h"  // Assuming DateTime is used for date/time handling

/*******************************************************
 * Function Name: Derived class User Menu constructor
 * Purpose: Creates Menu using MenuOption derived class
 * It also initializes the CSV file 
 *******************************************************/
UserMenu::UserMenu() : Menu("Manage User Accounts") {
    // Add options to the user menu
    MenuOption op1('1', "Open new account", "Show details");
    MenuOption op2('2', "Login", "Show details");
    MenuOption op3('3', "Logout", "Show details");
    MenuOption op4('4', "Remove Account", "Show details");
    MenuOption op5('5', "Reset Password", "Show details");
    MenuOption op6('6', "Help", "Show details");
    MenuOption op7('X', "Quit", "Show details");

    addOption(op1);
    addOption(op2);
    addOption(op3);
    addOption(op4);
    addOption(op5);
    addOption(op6);
    addOption(op7);

    initUserData();
}
/*******************************************************
 * Function Name: Username destructor
 * Purpose: Closes CSV file and saves the data stored in users vector
 *******************************************************/
UserMenu::~UserMenu() {
    // Save data to CSV before the object is destroyed
    saveData();

    // Optional: Close the file stream if opened earlier for reading
    if (inFile.is_open()) {
        inFile.close();
    }

    cout << "User data saved successfully. Exiting User Menu." << endl;
}
/*******************************************************
 * Function Name: initUserData
 * Purpose: streams data from CSV and saves 
 * Return: it returns a vector with users
 *******************************************************/
void UserMenu::initUserData() {
    ifstream inFile(USERS_DATA); // Assuming USERS_DATA points to users.csv
    if (inFile.fail()) {
        cout << "Unable to open the file: " << USERS_DATA << endl;
        return;
    }
    string line;
    getline(inFile, line); // Skip the header line
    while (getline(inFile, line)) {
        istringstream ss(line);
        string text;
        User user;

        getline(ss, text, ',');
        user.setId(stoi(text));
        getline(ss, text, ',');
        user.setUsername(text);
        getline(ss, text, ',');
        user.setPassword(text);
        getline(ss, text, ',');
        user.setRole(stoi(text));
        getline(ss, text, ',');
        user.setEmail(text);
        getline(ss, text, ',');
        // Get createDateTime
       /*getline(ss, text, ',');
        user.setCreateDT(parseDateTime(text));
        // Get loginDateTime
        getline(ss, text, ',');
        user.setLoginDT(parseDateTime(text));
        // Get logoutDateTime
        getline(ss, text, ',');
        user.setLogOutDT(parseDateTime(text));
        // Assuming other User attributes are parsed similarly
        */
        users.push_back(user);
    }
    inFile.close();
}
/*******************************************************
 * Function Name: saveData
 * Purpose: Saves data manipulated during create user, login, logout, etc
 * Return: CSV file with changes
 *******************************************************/
void UserMenu::saveData() {
    ofstream outFile(USERS_DATA);
    if (outFile.fail()) {
        cout << "Unable to open the file for writing: users.csv" << endl;
        return;
    }

    outFile << "ID,Username,Password,Role,Email,CreateDateTime,LoginDateTime,LogoutDateTime" << endl;
    for (const auto& user : users) {
        outFile << user.getId() << ","
            << user.getUsername() << ","
            << user.getPassword() << ","
            << user.getRole() << ","
            << user.getEmail() << ","
            << user.getCreateDT() << ","
            << user.getLoginDT() << ","
            << user.getLogOutDT() << endl;
    }
    outFile.close();
}
/*******************************************************
 * Function Name: activate
 * Purpose: Runs a loop based on menu options and user input
 *******************************************************/
void UserMenu::activate() {
    char choice = 0;
    do {
        choice = getInput();
        switch (choice) {
        case USER_CREATE:
            create();
            break;
        case USER_LOGIN:
            login();
            break;
        case USER_LOGOUT:
            logout();
            break;
        case USER_REMOVE:
            remove();
            break;
        case USER_RESET:
            reset();
            break;
        case USER_HELP:
            help();
            break;
        case USER_EXIT:
            std::cout << "Bye bye!" << std::endl;
            break;
        default:
            std::cout << "Invalid option" << std::endl;
        }
    } while (choice != 'X');
}
/*DateTime UserMenu::parseDateTime(const string& dateTimeStr) {
    istringstream ss(dateTimeStr);
    string datePart, timePart;

    // Split dateTimeStr into date and time parts by space
    getline(ss, datePart, ' ');  // Get the date part (M/D/YYYY)
    getline(ss, timePart, ' ');  // Get the time part (H:MM:S)

    // Parse the date part (M/D/YYYY)
    istringstream dateSS(datePart);
    string month, day, year;
    getline(dateSS, month, '/');
    getline(dateSS, day, '/');
    getline(dateSS, year, '/');

    Date date(stoi(year), stoi(month), stoi(day));

    // Parse the time part (H:MM:S)
    istringstream timeSS(timePart);
    string hour, minute, second;
    getline(timeSS, hour, ':');
    getline(timeSS, minute, ':');
    getline(timeSS, second, ':');

    Time time(stoi(hour), stoi(minute), stoi(second));

    // Construct and return DateTime object
    return DateTime(date, time);
}*/

/*******************************************************
 * Function Name: login
 * Purpose: logs a user using username or email
 * Return: returns a console output based on the success or failure
 * of the login action
 *******************************************************/
void UserMenu::login() {
    string enteredValue, enteredPassword;
    int attempts = 3;

    while (attempts > 0) {
        cout << "Enter username: ";
        cin >> enteredValue;
        cout << "Enter password: ";
        cin >> enteredPassword;

        for (User& u : users) {
            if (u.getUsername() == enteredValue || u.getEmail() == enteredValue && u.getPassword() == enteredPassword) {
                user = u;
                user.setLoginDT(DateTime::now());
                cout << "Login successful.\n";
                return;
            }
        }

        cout << "Invalid credentials. Attempts remaining: " << --attempts << "\n";
    }

    cout << "Login failed after 3 attempts.\n";
}
// Method to log out a user
void UserMenu::logout() {
    user.setLogOutDT(DateTime::now());
    cout << "Logged out.\n";
}
// Method to create a user
void UserMenu::create() {
    // Gather input from the user for creating a new account
    string username, password, email;
    int role;

    cout << "Create a new username: ";
    cin >> username;

    cout << "Create a password: ";
    cin >> password;

    cout << "Enter your email: ";
    cin >> email;

    // Define role (you could have this input or assign it automatically)
    cout << "Enter role (1 = admin, 2 = user, -1 = guest): ";
    cin >> role;

    // Create a new User object
    User newUser;
    newUser.setUsername(username);
    newUser.setPassword(password);
    newUser.setEmail(email);
    newUser.setRole(role);

    // Create a unique ID for the new user (incremental ID based on existing user size)
    int newId = 1001 + users.size();  // Example starting ID at 1001
    newUser.setId(newId);

    // Set the creation date-time to current system date-time
    DateTime currentDateTime = DateTime().now();  // Assuming DateTime has getSystemDT()
    newUser.setCreateDT(currentDateTime);

    // Add the new user to the list
    users.push_back(newUser);

    // Save updated users data to the CSV file
    saveData();

    // Confirmation message
    cout << "User account created successfully!" << endl;
}


// Method to remove a user
void UserMenu::remove() {
    // Remove user logic
}

// Method to reset a user account (only for admins)
void UserMenu::reset() {
    string password, newPassword;

    if (user.getRole() == 1) {
        // Reset password logic for admin
        cout << "Provide current password: ";
        cin >> password;
        if (password == user.getPassword())
        {
            cout << "Enter your new password" << endl;
            cin >> newPassword;
            user.setPassword(newPassword);
        }
        else
        {
            cout << "Try again later" << endl;
        }
    }
    else {
        cout << "Only admins can reset passwords.\n";
    }
}

// Help menu
void UserMenu::help()
{
    // Show the cout instructions on how to use this application
    cout << "*** Instructions on how to use this application ***" << endl;
    cout << "Start selecting an option from the menu:" << endl;
    cout << "1) Create a new account adding the information required" << endl;
    cout << "2) Enter username or email to login to account" << endl;
    cout << "3) Logout from current account" << endl;
    cout << "4) If the role permits, remove account" << endl;
    cout << "5) If the role permits, resets your old password" << endl;
    cout << "6) Help menu showing the options of the User Accounts Program" << endl;
    cout << "x) Exit the application " << endl;
}