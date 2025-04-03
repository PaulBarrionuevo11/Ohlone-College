 #ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include <iostream>
using namespace std;

template <typename T>
class LinkedList;
template <typename T>
class Iterator;

/**************************** NODE CLASS **************************************/
/*******************************************************
 * Purpose: Blueprint of Node class that is instantiated with an element that represents
 * the data of type T. Node has two elements that will be saved in previous
 * and next and can be accessed depending in the node where you are at
 *
 * @param data of type T, two values of previous and next.
 * Node has complete access to LinkedList and Iterator class
 * @note
 *******************************************************/
template <typename T>
class Node {
public:
    Node(T element);
    T data;
    Node* previous;
    Node* next;
    friend class LinkedList<T>;
    friend class Iterator<T>;
};

//********************************** Implementation of Node class
/*******************************************************
 * Purpose: Initializes a Node which is not linked with
 * any previous or next Node
 *
 * @param element of type T
 * @note nullptr denotes that the Node is uniquely created with no ancestors or
 * predecessors this could represent an empty Node List where
 * there is only one element
 *******************************************************/
template <typename T>
Node<T>::Node(T element) {
    data = element;
    previous = nullptr;
    next = nullptr;
}
/******************************************************************/

/**************************** ITERATOR CLASS **************************************/
/*******************************************************
 * Purpose: Blueprint of the Iterator class which is directly interacts between
 * the Node and the LinkedList class.
 *
 * @params public methods and constructor with no arguments.
 * private member attributes will be the position of the current Node
 * the container created in the linked list to accommodate the new node
 * @note
 *******************************************************/
template <typename T>
class Iterator {
public:
    Iterator();
    T get() const;
    void next();
    void previous();
    bool equals(Iterator<T> other) const;
    // prefix increment
    Iterator<T>& operator++();
    // postfix increment
    Iterator<T> operator++(int);
    // prefix decrement
    Iterator<T>& operator--();
    // postfix decrement
    Iterator<T> operator--(int);
    // Dereference operator to access the data at the current node
    T& operator*() const {
        return position->data;
    }
    // Overload the != operator
    bool operator!=(const Iterator& other) const {
        return position != other.position;
    }
private:
    Node<T>* position;
    LinkedList<T>* container;
    friend class LinkedList<T>;
};

//********************************** Implementation of Iterator class
/*******************************************************
 * Purpose: Initializes an empty Iterator with null pointers
 *
 * @param private Node position and Linked List container
 *******************************************************/
template <typename T>
Iterator<T>::Iterator() {
    position = nullptr;
    container = nullptr;
}
/*******************************************************
 * Purpose: looks for the position of the specific data that
 * the node has and returns the value
 *
 * @return data of type T
 *******************************************************/
template <typename T>
T Iterator<T>::get() const {
    return position->data;
}
/*******************************************************
 * Purpose: looks for the position of the specific data that
 * the node has and returns the value
 *
 * @return data of type T
 *******************************************************/
template <typename T>
void Iterator<T>::next() {
    position = position->next;
}

template <typename T>
void Iterator<T>::previous() {
    position = (position == nullptr) ? container->last : position->previous;
}

template <typename T>
bool Iterator<T>::equals(Iterator<T> other) const {
    return position == other.position;
}
// Prefix increment: ++iterator
template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    if (position) {
        position = position->next;
    }
    return *this;
}


// Postfix increment: iterator++
template <typename T>
Iterator<T> Iterator<T>::operator++(int) {
    Iterator<T> temp = *this; // Save the current state
    if (position) {
        position = position->next;
    }
    return temp; // Return original iterator state
}

// Prefix decrement: --iterator
template <typename T>
Iterator<T>& Iterator<T>::operator--() {
    if (position) {
        position = position->previous;
    }
    return *this;
}

// Postfix decrement: iterator--
template <typename T>
Iterator<T> Iterator<T>::operator--(int) {
    Iterator<T> temp = *this; // Save the current state
    if (position) {
        position = position->previous;
    }
    return temp; // Return original iterator state
}

/******************************************************************/

/**************************** LINKED LIST CLASS **************************************/
/*******************************************************
 * Purpose: Blueprint of Node class that is instantiated with an element that represents
 * the data of type T. Node has two elements that will be saved in previous
 * and next and can be accessed depending in the node where you are at
 *
 * @param data of type T, two values of previous and next.
 * Node has complete access to LinkedList and Iterator class
 * @note
 *******************************************************/
template <typename T>
class LinkedList {
public:
    LinkedList();
    void insert(T element);
    void insert(Iterator<T> iter, T element);
    T get(int k);
    Iterator<T> erase(Iterator<T> iter);
    Iterator<T> begin();
    Iterator<T> end();

    void sort();
    void selectionSort();
    int search(T element);
    void remove(T element);
    void print();
    Node<T>* getFirst() const { return first; }
    void setFirst(Node<T>* newFirst) {
        if (newFirst == nullptr) {
            first = nullptr; // If null, list is empty
        }
        else {
            first = newFirst;
            first->previous = nullptr; // Set previous of new first to null
        }
    }    Node<T>* getLast() const { return last; }
protected:
    Node<T>* first;
    Node<T>* last;
    Node<T>* last_node;
    friend class Iterator<T>;
private:
    // Do I need a Node with position argument?
    int last_index;
};

//********************************** Implementation of LinkedList class
template <typename T>
LinkedList<T>::LinkedList() {
    first = nullptr;
    last = nullptr;
    last_node = nullptr;
    last_index = -1;
}
template <typename T>
Iterator<T> LinkedList<T>::erase(Iterator<T> iter) {
    Node<T>* remove = iter.position;
    Node<T>* before = remove->previous;
    Node<T>* after = remove->next;
    if (remove == first) {
        first = after;
    }
    else {
        before->next = after;
    }

    if (remove == last) {
        last = before;
    }
    else {
        after->previous = before;
    }
    delete remove;
    iter.position = after;
    return iter;
}
template <typename T>
Iterator<T> LinkedList<T>::begin() {
    Iterator<T> iter;
    iter.position = first;
    iter.container = this;
    return iter;
}
template <typename T>
Iterator<T> LinkedList<T>::end() {
    Iterator<T> iter;
    iter.position = nullptr;
    iter.container = this;
    return iter;
}
template <typename T>
void LinkedList<T>::insert(T element) {
    Node<T>* new_node = new Node<T>(element);
    if (last == nullptr) {
        first = new_node;
        last = new_node;
    }
    else {
        new_node->previous = last;
        last->next = new_node;
        last = new_node;
    }
}
template <typename T>
void LinkedList<T>::insert(Iterator<T> iter, T element) {
    if (iter.position == nullptr) {
        insert(element);
        return;
    }
    Node<T>* after = iter.position;
    Node<T>* before = after->previous;
    Node<T>* new_node = new Node<T>(element);
    new_node->previous = before;
    new_node->next = after;
    after->previous = new_node;
    if (before == nullptr) {
        first = new_node;
    }
    else {
        before->next = new_node;
    }
}
template <typename T>
T LinkedList<T>::get(int k) {
    Node<T>* n = first;
    int i = 0;
    while (i < k && n != nullptr) {
        n = n->next;
        i++;
    }
    return (n != nullptr) ? n->data : T();
}
template <typename T>
void LinkedList<T>::sort()
{
    selectionSort();
}
template <typename T>
void LinkedList<T>::selectionSort() {
    if (first == nullptr || first->next == nullptr) return;
    // Outer loop: Traverse the list
    for (Node<T>* i = first; i != nullptr; i = i->next) {
        Node<T>* min = i;

        // Inner loop: Find the minimum element in the unsorted portion
        for (Node<T>* j = i->next; j != nullptr; j = j->next) {
            if (j->data < min->data) {
                min = j;
            }
        }
        // Swap the data of the current node with the node containing the minimum element
        if (min != i) {
            T temp = i->data;
            i->data = min->data;
            min->data = temp;
        }
    }
}
template <typename T>
int LinkedList<T>::search(T element)
{
    Node<T>* current = first;
    int index = 0;
    // Traverse the list
    while (current != nullptr) {
        if (current->data == element) {
            return index;  // Return the index if the element is found
        }
        current = current->next;
        index++;
    }
    return -1;
}
template <typename T>
void LinkedList<T>::remove(T element) {
    Node<T>* current = first;

    // Traverse the list to find the node with the element
    while (current != nullptr) {
        if (current->data == element) {
            // If the node to remove is the first node
            if (current == first) {
                first = current->next;
                if (first != nullptr) {
                    first->previous = nullptr;  // Update the new first node's previous pointer
                }
            }
            // If the node to remove is the last node
            if (current == last) {
                last = current->previous;
                if (last != nullptr) {
                    last->next = nullptr;  // Update the new last node's next pointer
                }
            }
            // If the node is in the middle
            if (current->previous != nullptr) {
                current->previous->next = current->next;
            }
            if (current->next != nullptr) {
                current->next->previous = current->previous;
            }

            // Free the memory
            delete current;
            return;  // Exit after removing the first matching element
        }
        current = current->next;
    }
}
template <typename T>
void LinkedList<T>::print()
{
    Node<T>* current = first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
/******************************************************************/

#endif

