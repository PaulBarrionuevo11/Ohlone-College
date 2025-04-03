#include "person.h"
#include <iostream>
#include "contactManager.h"

using namespace std;

ContactManager::ContactManager() : ArrayList<Person>() {
}

void ContactManager::sort() {
    char val;
    cout << "Enter option for ascending or descending: " << endl;
    cout << "Ascending = a or Descending = d : " << endl;
    cin >> val;

    if (val == 'a') {
        // Sort in ascending order
        quickSort(0, this->size() - 1, true);
    }
    else if (val == 'd') {
        // Sort in descending order
        quickSort(0, this->size() - 1, false);
    }
}

int ContactManager::partition(int low, int high, bool ascending) {
    Person pivot = this->buffer[high];  // Choose the last element as the pivot
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (ascending) {
            if (this->buffer[j] < pivot) {  // For ascending order
                i++;
                swap(this->buffer[i], this->buffer[j]);
            }
        }
        else {
            if (this->buffer[j] > pivot) {  // For descending order
                i++;
                swap(this->buffer[i], this->buffer[j]);
            }
        }
    }
    // Swap the pivot element with the element at i+1 to place it in the correct sorted position
    swap(this->buffer[i + 1], this->buffer[high]);
    return i + 1;
}

void ContactManager::quickSort(int low, int high, bool ascending) {
    if (low < high) {
        int pi = partition(low, high, ascending);

        // Recursively sort the elements before and after the partition
        quickSort(low, pi - 1, ascending);
        quickSort(pi + 1, high, ascending);
    }
}

void ContactManager::remove(Person p) {
    int index = search(p);
    if (index != -1) {
        removeAt(index);
    }
}

void ContactManager::print() const { // print as const
    for (int i = 0; i < size(); i++) {
        std::cout << at(i) << std::endl;
    }
}
