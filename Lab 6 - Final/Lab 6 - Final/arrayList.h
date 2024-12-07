#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#include "AbstractArrayList.h"

using namespace std;

template<typename T>
class ArrayList : public AbstractArrayList<T> {
public:
    ArrayList();
    ~ArrayList();
    //int size() const;

    void insert(T element);
    void insert(int k, T element);

    T& at(int k) const;
    void removeAt(int k);

    void sort();
    int search(T elment);

    virtual void remove(T element) { };

    void print() const;

protected:
    T* buffer;
    int capacity;
    bool sorted = false;
    //int len;
    void grow_if_necessary();
    void bubbleSort();
    void swap(T& a, T& b);
    int binarySearch(T element);
    int searchSeq(T elment);
};

template<typename T>
ArrayList<T>::ArrayList() {
    const int INITIAL_CAPACITY = 5;
    buffer = new T[INITIAL_CAPACITY]; // Use T instead of int
    capacity = INITIAL_CAPACITY;
    this->len = 0;
}

template<typename T>
ArrayList<T>::~ArrayList() {
    if (buffer != nullptr) {
        delete[] buffer;
    }
    buffer = nullptr;
}

template <typename T>
T& ArrayList<T>::at(int k) const { // Add const here
    if (k < 0 || k >= this->size()) {
        throw std::out_of_range("Index out of range");
    }
    return buffer[k];
}

template <typename T>
void ArrayList<T>::print() const { // Add const here
    for (int i = 0; i < this->size(); i++) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;
}
template<typename T>
void ArrayList<T>::insert(T element) {
    grow_if_necessary();
    buffer[this->size()] = element;
    //len++;
    this->increment();
}

template<typename T>
void ArrayList<T>::insert(int k, T element) { // The index should be an int
    if (k < 0 || k > this->size()) {
        throw std::out_of_range("Index out of range");
    }
    grow_if_necessary();
    for (int i = this->size(); i > k; i--) {
        buffer[i] = buffer[i - 1];
    }
    buffer[k] = element;
    //len++; 
    this->increment();
}

template<typename T>
void ArrayList<T>::removeAt(int k) { // The index should be an int
    if (k < 0 || k >= this->size()) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = k + 1; i < this->size(); i++) {
        buffer[i - 1] = buffer[i];
    }
    //len--;
    this->increment();
}

template<typename T>
void ArrayList<T>::grow_if_necessary() {
    if (this->size() == capacity) {
        capacity = 2 * capacity;
        T* larger_buffer = new T[capacity]; // Use T instead of int
        for (int i = 0; i < this->size(); i++) {
            larger_buffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = larger_buffer;
    }
}

template <typename T>
void ArrayList<T>::sort() {
    bubbleSort();
    sorted = true;
}

template <typename T>
void ArrayList<T>::bubbleSort() {
    for (int i = 0; i < this->size() - 1; i++) {
        for (int j = 0; j < this->size() - i - 1; j++) {
            if (buffer[j] > buffer[j + 1]) {
                // Swap elements
                swap(buffer[j], buffer[j + 1]);
            }
        }
    }
}

template <typename T>
void ArrayList<T>::swap(T& a, T& b) {
    // Swap elements
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
int ArrayList<T>::search(T element) {
    //return sorted ? binarySearch(element) : searchSeq(element);
    if (sorted) {
        return binarySearch(element);
    }
    else {
        return searchSeq(element);
    }
}

template <typename T>
int ArrayList<T>::searchSeq(T element) {
    for (int i = 0; i < this->size(); i++) {
        if (buffer[i] == element) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int ArrayList<T>::binarySearch(/*int array[], int size,*/ T element) {
    int low = 0;
    int high = this->size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (buffer[mid] == element)
            return mid;
        else if (buffer[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Element not found
}

#endif
