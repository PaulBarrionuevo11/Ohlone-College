#ifndef USER_H
#define USER_H

#include <iostream>
#include "dateTime.h"  // Assuming you use DateTime for handling date-time fields
using namespace std;

class User {
private:
    int id;
    string username;
    string password;
    int role;            // For roles like admin, regular user, etc.
    string email;
    DateTime createDT;    // Create DateTime
    DateTime loginDT;     // Login DateTime
    DateTime logoutDT;    // Logout DateTime

public:
    // Constructors
    User();
    User(int id, const string& username, const string& password, int role, const string& email);

    // Getters
    int getId() const;
    string getUsername() const;
    string getPassword() const;
    int getRole() const;
    string getEmail() const;
    DateTime getCreateDT() const;
    DateTime getLoginDT() const;
    DateTime getLogOutDT() const;

    // Setters
    void setId(int id);
    void setUsername(const string& username);
    void setPassword(const string& password);
    void setRole(int role);
    void setEmail(const string& email);
    void setCreateDT(const DateTime& createDT);
    void setLoginDT(const DateTime& loginDT);
    void setLogOutDT(const DateTime& logoutDT);
};

#endif
