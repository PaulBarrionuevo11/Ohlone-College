#ifndef LINKED_LIST_SET_H
#define LINKED_LIST_SET_H

#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;


// Hash function for strings
int hash_code(const string& str) {
	int h = 0;
	for (int i = 0; i < str.length(); i++) {
		h = 31 * h + str[i];
	}
	return h;
}

template <typename T>
class LinkedListSet : public LinkedList<T>
{
public:
	LinkedListSet(int buckets); // Constructor to define number of buckets

	void insert(T element); // Generate hashcode
	void erase(T element);  // Generate hashcode
	int count() const;      // Return number of unique elements
	void print();           // Print the entire set

private:
	vector<T> buckets;      // Buckets to organize elements
	int num_buckets;		// Number of buckets in the set
};

// Constructor
template <typename T>
LinkedListSet<T>::LinkedListSet(int nbuckets)
{
	num_buckets = nbuckets;
	buckets.resize(nbuckets, T()); // Initialize buckets
}
// Insert element into the set
template <typename T>
void LinkedListSet<T>::insert(T element) {
	int h = hash_code(element) % num_buckets; // Generate hash index
	if (h < 0) h += num_buckets;

	// Check if element already exists in the bucket
	for (const T& item : this->buckets) {
		if (item == element) {
			return; // Element already exists, no insertion
		}
	}

	// Add element to the bucket
	buckets[h] = element;
	this->insert(element); // Add to the underlying linked list
}
// Erase element from the set
template <typename T>
void LinkedListSet<T>::erase(T element) {
	int h = hash_code(element) % num_buckets; // Generate hash index
	if (h < 0) h += num_buckets;

	if (buckets[h] == element) {
		buckets[h] = T(); // Clear bucket
		this->remove(element); // Remove from linked list
	}
}
// Count the number of unique elements
template <typename T>
int LinkedListSet<T>::count() const {
	int unique_count = 0;
	for (const T& item : buckets) {
		if (item != T()) {
			unique_count++;
		}
	}
	return unique_count;
}
template <typename T>
void LinkedListSet<T>::print() {
	cout << "Set elements:" << endl;
	for (const T& item : buckets) {
		if (item != T()) {
			cout << item << " ";
		}
	}
	cout << endl;
}
#endif // !LINKED_LIST_SET_H
