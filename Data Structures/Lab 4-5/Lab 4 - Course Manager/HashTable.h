#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include "Faculty.h"

using namespace std;

//int hash_code(const string& str);

template<typename T>
class HashTable;
template<typename T>
class Iterator2;

template<typename T>
class Node2 {
private:
    T data;
    Node2<T>* next;

    friend class HashTable<T>;
    friend class Iterator2<T>;
};

template<typename T>
class Iterator2 {
public:
    T get() const;
    void next();
    bool equals(const Iterator2<T>& other) const;
private:
    const HashTable<T>* container;
    int bucket_index;
    Node2<T>* current;

    friend class HashTable<T>;
};


template<typename T>
class HashTable {
public:
    HashTable<T>(int nbuckets);
    int count(const T& x);
    void insert(const T& x);
    void insert(string key, const T& t);
    void erase(const T& x);
    Iterator2<T> begin() const;
    Iterator2<T> end() const;
    int size() const;

private:
    vector<Node2<T>*> buckets;
    int current_size;
    int hash_code(const string& key);

    friend class Iterator2<T>;
};
template<typename T>
int HashTable<T>::hash_code(const string& key) {
    string str = key;
    int h = 0;
    for (int i = 0; i < str.length(); i++) {
        h = 31 * h + str[i];
    }
    return h;
}

template<typename T>
HashTable<T>::HashTable(int nbuckets) {
    for (int i = 0; i < nbuckets; i++) {
        buckets.push_back(nullptr);
    }
    current_size = 0;
}
template<typename T>
int HashTable<T>::count(const T& x) {
    int h = hash_code(x);
    h = h % buckets.size();
    if (h < 0) {
        h = -h;
    }

    Node2<T>* current = buckets[h];
    while (current != nullptr) {
        if (current->data == x) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

template<typename T>
void HashTable<T>::insert(string key, const T& x)
{
    int h = hash_code(key);
    h = h % buckets.size();
    if (h < 0) {
        h = -h;
    }
    Node2<T>* current = buckets[h];
    while (current != nullptr) {
        if (current->data == x) {
            return;
        }
        // Already in the set
        current = current->next;
    }
    Node2<T>* new_node = new Node2<T>;
    new_node->data = x;
    new_node->next = buckets[h];
    buckets[h] = new_node;
    current_size++;
}
template<typename T>
void HashTable<T>::insert(const T& x) {
    int h = hash_code(x);
    h = h % buckets.size();
    if (h < 0) {
        h = -h;
    }

    Node2<T>* current = buckets[h];
    while (current != nullptr) {
        if (current->data == x) {
            return;
        }
        // Already in the set
        current = current->next;
    }
    Node2<T>* new_node = new Node2<T>;
    new_node->data = x;
    new_node->next = buckets[h];
    buckets[h] = new_node;
    current_size++;
}
template<typename T>
void HashTable<T>::erase(const T& x) {
    int h = hash_code(x);
    h = h % buckets.size();
    if (h < 0) {
        h = -h;
    }

    Node2<T>* current = buckets[h];
    Node2<T>* previous = nullptr;
    while (current != nullptr) {
        if (current->data == x) {
            if (previous == nullptr) {
                buckets[h] = current->next;
            }
            else {
                previous->next = current->next;
            }
            delete current;
            current_size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}
template<typename T>
int HashTable<T>::size() const {
    return current_size;
}
template<typename T>
Iterator2<T> HashTable<T>::begin() const {
    Iterator2<T> iter;
    iter.current = nullptr;
    iter.bucket_index = -1;
    iter.container = this;
    iter.next();
    return iter;
}
template<typename T>
Iterator2<T> HashTable<T>::end() const {
    Iterator2<T> iter;
    iter.current = nullptr;
    iter.bucket_index = (int)buckets.size();
    iter.container = this;
    return iter;
}
template<typename T>
T Iterator2<T>::get() const {
    return current->data;
}
template<typename T>
bool Iterator2<T>::equals(const Iterator2<T>& other) const {
    return current == other.current;
}
template<typename T>
void Iterator2<T>::next() {
    if (bucket_index >= 0 && current->next != nullptr) {
        // Advance in the same bucket
        current = current->next;
    }
    else {
        // Move to the next bucket
        do {
            bucket_index++;
        } while (bucket_index < container->buckets.size()
            && container->buckets[bucket_index] == nullptr);

        if (bucket_index < container->buckets.size()) {
            // Start of next bucket
            current = container->buckets[bucket_index];
        }
        else {
            // No more buckets
            current = nullptr;
        }
    }
}

#endif