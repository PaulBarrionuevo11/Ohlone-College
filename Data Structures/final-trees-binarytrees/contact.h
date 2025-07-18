#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

using namespace std;

/*******************************************************
 * Class Name: Contact
 * Purpose: Represents a contact person with multiple attributes,
 *          such as name, address, phone numbers, and email.
 *******************************************************/
class Contact
{
public:
    /*******************************************************
     * Function Name: Contact (Constructor)
     * Purpose: Initializes a Contact object with given details.
     * Parameters:
     *   - string id: Unique identifier for the contact.
     *   - string fName: First name of the contact.
     *   - string mName: Middle name of the contact.
     *   - string lName: Last name of the contact.
     *   - string company: Company name associated with the contact.
     *   - string address: Address of the contact.
     *   - string city: City where the contact resides.
     *   - string county: County where the contact resides.
     *   - string state: State where the contact resides.
     *   - string zip: ZIP code of the contact.
     *   - string phone1: Primary phone number.
     *   - string phone2: Secondary phone number.
     *   - string email: Email address of the contact.
     *******************************************************/
    Contact(string fName, string mName, string lName, string company,
        string address, string city, string county, string state, string zip, string phone1, string phone2, string email);

    /*******************************************************
     * Function Name: Contact (Default Constructor)
     * Purpose: Initializes a Contact object with default values.
     *******************************************************/
    Contact() = default;

    /*******************************************************
     * Function Name: ~Contact (Destructor)
     * Purpose: Destroys the Contact object, releasing any resources.
     *******************************************************/
    ~Contact();

    /*******************************************************
     * Function Name: Getters
     * Purpose: Retrieve values of private members.
     * Return: Corresponding string value for each attribute.
     *******************************************************/
    string getZip() const;
    string getPhone1() const;
    string getPhone2() const;
    string getFirstName() const;
    string getMiddleName() const;
    string getLastName() const;
    string getCompany() const;
    string getAddress() const;
    string getCity() const;
    string getCounty() const;
    string getState() const;
    string getEmail() const;

    /*******************************************************
     * Function Name: Setters
     * Purpose: Set or modify the values of private members.
     * Parameters: Corresponding string value for each attribute.
     *******************************************************/
    void setZip(string _zip);
    void setPhone1(string _phone1);
    void setPhone2(string _phone2);
    void setFirstName(string _fn);
    void setMiddleName(string _mn);
    void setLastName(string _ln);
    void setCompany(string _company);
    void setAddress(string _address);
    void setCity(string _city);
    void setCounty(string _county);
    void setState(string _state);
    void setEmail(string _email);

    /*******************************************************
     * Function Name: operator= (Assignment Operator)
     * Purpose: Assigns the values from one Contact object to another.
     * Parameters:
     *   - const Contact& p: Reference to another Contact object.
     * Return: Reference to the modified Contact object (*this).
     *******************************************************/
    Contact& operator=(const Contact& p);

    /*******************************************************
     * Function Name: operator< (Less Than Operator)
     * Purpose: Compares two Contact objects based on their attributes.
     * Parameters:
     *   - const Contact& p: Reference to another Contact object.
     * Return: True if the current Contact is less than the other Contact.
     *******************************************************/
    bool operator<(const Contact& p) const;

    /*******************************************************
     * Function Name: operator> (Greater Than Operator)
     * Purpose: Compares two Contact objects based on their attributes.
     * Parameters:
     *   - const Contact& p: Reference to another Contact object.
     * Return: True if the current Contact is greater than the other Contact.
     *******************************************************/
    bool operator>(const Contact& p) const;

    /*******************************************************
     * Function Name: operator<= (Less Than or Equal To Operator)
     * Purpose: Checks if the current Contact is less than or equal to another Contact.
     * Parameters:
     *   - const Contact& p: Reference to another Contact object.
     * Return: True if the condition is met.
     *******************************************************/
    bool operator<=(const Contact& p) const;

    /*******************************************************
     * Function Name: operator== (Equality Operator)
     * Purpose: Checks if two Contact objects are equal.
     * Parameters:
     *   - const Contact& p: Reference to another Contact object.
     * Return: True if the attributes of both objects are equal.
     *******************************************************/
    bool operator==(const Contact& p) const;

    /*******************************************************
     * Function Name: operator<< (Stream Insertion Operator)
     * Purpose: Outputs the details of a Contact object to an ostream.
     * Parameters:
     *   - ostream& os: Reference to the output stream.
     *   - const Contact& p: Reference to a Contact object.
     * Return: Reference to the modified ostream.
     *******************************************************/
    friend ostream& operator<<(ostream& os, const Contact& p);

private:
    // Private member variables to store contact details.
    string firstName, middleName, lastName; // Name components
    string company;                        // Company name
    string address;                        // Address details
    string city, county, state;            // Location details
    string zip;                            // ZIP code
    string phone1, phone2;                 // Contact phone numbers
    string email;                          // Email address
};

#endif // !CONTACT_H

