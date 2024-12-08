// Node1.h
#ifndef NODE1_H
#define NODE1_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class Tree;

template<typename T>
class Node1 {
public:
    T data;
    vector<Node1<T>*> children;

    int size() const;
    int number_of_leaves() const;
    void print(int level = 0) const;

    ~Node1(); // Recursive destructor to clean up dynamically allocated nodes
    friend class Tree<T>;
};

template<typename T>
class Tree {
public:
    Tree();  // Default constructor
    Tree(T root_data);  // Constructor with root data
    ~Tree();  // Destructor to clean up nodes

    void add_subtree(const Tree<T>& subtree);
    int size() const;
    int number_of_leaves() const;
    void print() const;
    Node1<T>* root;
};

// Tree Implementation
template<typename T>
Tree<T>::Tree() : root(nullptr) {}

template<typename T>
Tree<T>::Tree(T root_data) {
    root = new Node1<T>;
    root->data = root_data;
}

template<typename T>
Tree<T>::~Tree() {
    delete root;
}

template<typename T>
void Tree<T>::add_subtree(const Tree<T>& subtree) {
    if (root) {
        root->children.push_back(subtree.root); // Share ownership (deep copy recommended for safety)
    }
}

template<typename T>
int Tree<T>::size() const {
    return root ? root->size() : 0;
}

template<typename T>
int Tree<T>::number_of_leaves() const {
    return root ? root->number_of_leaves() : 0;
}

template<typename T>
void Tree<T>::print() const {
    if (root) {
        root->print();
    }
}

// Node Implementation
template<typename T>
Node1<T>::~Node1() {
    for (Node1<T>* child : children) {
        delete child;
    }
}

template<typename T>
int Node1<T>::size() const {
    int sum = 0;
    for (Node1<T>* child : children) {
        sum += child->size();
    }
    return 1 + sum;
}

template<typename T>
int Node1<T>::number_of_leaves() const {
    if (children.empty()) return 1;
    int sum = 0;
    for (const Node1<T>* child : children) {
        sum += child->number_of_leaves();
    }
    return sum;
}

template<typename T>
void Node1<T>::print(int level) const {
    for (int i = 0; i < level; ++i) cout << "  ";
    cout << data << endl;
    for (const Node1<T>* child : children) {
        child->print(level + 1);
    }
}
#endif // NODE1_H
