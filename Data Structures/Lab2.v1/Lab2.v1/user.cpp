#include "user.h"

/*******************************************************
 * Function Name: User
 * Purpose: Default constructor for User class, initializes
 *          id and role to 0, and other members to their
 *          default values.
 *******************************************************/
User::User() : id(0), role(0) {}

/*******************************************************
 * Function Name: User::User
 * Purpose: Parameterized constructor for User class, initializes
 *          all member variables with provided values.
 * Parameter: id - user ID
 *            username - user's username
 *            password - user's password
 *            role - user's role in the system
 *            email - user's email address
 *******************************************************/
User::User(int id, const string& username, const string& password, int role, const string& email)
    : id(id), username(username), password(password), role(role), email(email), createDT(), loginDT(), logoutDT() {}

/*******************************************************
 * Function Name: getId
 * Purpose: Returns the ID of the user.
 * Return: int - the user's ID
 *******************************************************/
int User::getId() const {
    return id;
}

/*******************************************************
 * Function Name: getUsername
 * Purpose: Returns the username of the user.
 * Return: string - the user's username
 *******************************************************/
string User::getUsername() const {
    return username;
}

/*******************************************************
 * Function Name: getPassword
 * Purpose: Returns the password of the user.
 * Return: string - the user's password
 *******************************************************/
string User::getPassword() const {
    return password;
}

/*******************************************************
 * Function Name: getRole
 * Purpose: Returns the role of the user.
 * Return: int - the user's role
 *******************************************************/
int User::getRole() const {
    return role;
}

/*******************************************************
 * Function Name: getEmail
 * Purpose: Returns the email of the user.
 * Return: string - the user's email address
 *******************************************************/
string User::getEmail() const {
    return email;
}

/*******************************************************
 * Function Name: UgetCreateDT
 * Purpose: Returns the creation date and time of the user account.
 * Return: DateTime - the user's account creation DateTime
 *******************************************************/
DateTime User::getCreateDT() const {
    return createDT;
}

/*******************************************************
 * Function Name: getLoginDT
 * Purpose: Returns the last login date and time of the user.
 * Return: DateTime - the user's last login DateTime
 *******************************************************/
DateTime User::getLoginDT() const {
    return loginDT;
}

/*******************************************************
 * Function Name: getLogOutDT
 * Purpose: Returns the last logout date and time of the user.
 * Return: DateTime - the user's last logout DateTime
 *******************************************************/
DateTime User::getLogOutDT() const {
    return logoutDT;
}

/*******************************************************
 * Function Name: setId
 * Purpose: Sets the user's ID.
 * Parameter: id - the new user ID
 *******************************************************/
void User::setId(int id) {
    this->id = id;
}

/*******************************************************
 * Function Name: setUsername
 * Purpose: Sets the user's username.
 * Parameter: username - the new username
 *******************************************************/
void User::setUsername(const std::string& username) {
    this->username = username;
}

/*******************************************************
 * Function Name: setPassword
 * Purpose: Sets the user's password.
 * Parameter: password - the new password
 *******************************************************/
void User::setPassword(const std::string& password) {
    this->password = password;
}

/*******************************************************
 * Function Name: setRole
 * Purpose: Sets the user's role.
 * Parameter: role - the new role
 *******************************************************/
void User::setRole(int role) {
    this->role = role;
}

/*******************************************************
 * Function Name: setEmail
 * Purpose: Sets the user's email.
 * Parameter: email - the new email address
 *******************************************************/
void User::setEmail(const std::string& email) {
    this->email = email;
}

/*******************************************************
 * Function Name: setCreateDT
 * Purpose: Sets the account creation DateTime of the user.
 * Parameter: createDT - the new creation DateTime
 *******************************************************/
void User::setCreateDT(const DateTime& createDT) {
    this->createDT = createDT;
}

/*******************************************************
 * Function Name: setLoginDT
 * Purpose: Sets the last login DateTime of the user.
 * Parameter: loginDT - the new login DateTime
 *******************************************************/
void User::setLoginDT(const DateTime& loginDT) {
    this->loginDT = loginDT;
}

/*******************************************************
 * Function Name: setLogOutDT
 * Purpose: Sets the last logout DateTime of the user.
 * Parameter: logoutDT - the new logout DateTime
 *******************************************************/
void User::setLogOutDT(const DateTime& logoutDT) {
    this->logoutDT = logoutDT;
}

