#ifndef S_CONTACT_LIST_H
#define S_CONTACT_LIST_H

#include "ArrayList.h"
#include "Person.h"
#include <iostream>

using namespace std;

class ContactList : public ArrayList<Person> {
public:
    ContactList();
    void sort();  // Sorting method with user input for ascending or descending
    void remove(Person p);
    void print() const;

private:
    // Updated quickSort and partition functions to accept sorting order
    void quickSort(int low, int high, bool ascending);
    int partition(int low, int high, bool ascending);
};

#endif

