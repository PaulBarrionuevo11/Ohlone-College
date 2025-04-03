#ifndef S_CONTACT_LIST_H
#define S_CONTACT_LIST_H

#include "arrayList.h"
#include "person.h"
#include <iostream>

using namespace std;

class ContactManager : public ArrayList<Person> {
public:
    ContactManager();
    void sort();  // Sorting method with user input for ascending or descending
    void remove(Person p);
    void print() const;

private:
    // Updated quickSort and partition functions to accept sorting order
    void quickSort(int low, int high, bool ascending);
    int partition(int low, int high, bool ascending);
};

#endif

