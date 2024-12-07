#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class Tree;

template<typename T>
class NodeTree {
public:

private:
    vector<NodeTree<T>*> children;
    T data;

    int size() const;
    int number_of_leaves() const;
    void print() const;
    NodeTree<T>* getChild(int index) const;


    ~NodeTree(); // Recursive destructor to clean up dynamically allocated nodes
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
    NodeTree<T>* getRoot() const;

private:
    NodeTree<T>* root;
};

// Tree Implementation
template<typename T>
Tree<T>::Tree() : root(nullptr) {}

template<typename T>
Tree<T>::Tree(T root_data) {
    root = new NodeTree<T>;
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
NodeTree<T>::~NodeTree() {
    for (NodeTree<T>* child : children) {
        delete child;
    }
}

template<typename T>
int NodeTree<T>::size() const {
    int sum = 0;
    for (NodeTree<T>* child : children) {
        sum += child->size();
    }
    return 1 + sum;
}

template<typename T>
int NodeTree<T>::number_of_leaves() const {
    if (children.empty()) return 1;
    int sum = 0;
    for (const NodeTree<T>* child : children) {
        sum += child->number_of_leaves();
    }
    return sum;
}

template<typename T>
void NodeTree<T>::print() const {
    cout << data << endl;
    for (const NodeTree<T>* child : children) {
        child->print();
    }
}

/////////////

template<typename T>
NodeTree<T>* NodeTree<T>::getChild(int index) const {
    if (index >= 0 && index < children.size()) {
        return children[index];
    }
    return nullptr;
}

template<typename T>
NodeTree<T>* Tree<T>::getRoot() const {
    return root;
}