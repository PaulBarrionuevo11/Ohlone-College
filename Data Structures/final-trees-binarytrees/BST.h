#ifndef BinarySearchTree_H
#define BinarySearchTree_H

#include <string>
#include "BT.h"

using namespace std;


/*
   This class implements a binary search tree whose
   nodes hold strings.
*/
template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    /**
       Constructs an empty tree.
    */
    BinarySearchTree();

    /**
       Inserts a new node into the tree.
       @param element the element to insert
    */
    void insert(T element);

    /**
       Tries to find an element in the tree.
       @param element the element to find
       @return 1 if the element is contained in the tree
    */
    int count(T element) const;

    /**
       Tries to remove an element from the tree. Does nothing
       if the element is not contained in the tree.
       @param element the element to remove
    */
    void erase(T element);

    /**
     * Implement a search method
     * @param Template/string
     * compare two elements (operator overloading for a different class)
     */
    bool search(const T& element);

    /**
       Prints the contents of the tree in sorted order.
    */
    void print() const;

protected:
    /**
       Prints a node and all of its descendants in sorted order.
       @param parent the root of the subtree to print
    */
    void print(Node<T>* parent) const;

    /**
       Inserts a new node as a descendant of a given node.
       @param parent the root node
       @param new_node the node to insert
    */
    void add_node(Node<T>* parent, Node<T>* new_node) const;

    Node<T>* root;
};
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}
template <typename T>
void BinarySearchTree<T>::insert(T element)
{
    Node<T>* new_node = new Node<T>;
    new_node->data = element;
    new_node->left = nullptr;
    new_node->right = nullptr;
    if (root == nullptr)
    {
        root = new_node;
    }
    else
    {
        add_node(root, new_node);
    }
}
template <typename T>
int BinarySearchTree<T>::count(T element) const
{
    Node<T>* current = root;
    while (current != nullptr)
    {
        if (element < current->data)
        {
            current = current->left;
        }
        else if (element > current->data)
        {
            current = current->right;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
template <typename T>
void BinarySearchTree<T>::erase(T element)
{
    // Find node to be removed

    Node<T>* to_be_removed = root;
    Node<T>* parent = nullptr;
    bool found = false;
    while (!found && to_be_removed != nullptr)
    {
        if (element == to_be_removed->data)
        {
            found = true;
        }
        else
        {
            parent = to_be_removed;
            if (element < to_be_removed->data)
            {
                to_be_removed = to_be_removed->left;
            }
            else
            {
                to_be_removed = to_be_removed->right;
            }
        }
    }

    if (!found)
    {
        return;
    }

    // to_be_removed contains element

    // If one of the children is empty, use the other

    if (to_be_removed->left == nullptr || to_be_removed->right == nullptr)
    {
        Node<T>* new_child;
        if (to_be_removed->left == nullptr)
        {
            new_child = to_be_removed->right;
        }
        else
        {
            new_child = to_be_removed->left;
        }

        if (parent == nullptr) // Found in root
        {
            root = new_child;
        }
        else if (parent->left == to_be_removed)
        {
            parent->left = new_child;
        }
        else
        {
            parent->right = new_child;
        }
        return;
    }

    // Neither subtree is empty

    // Find smallest element of the right subtree

    Node<T>* smallest_parent = to_be_removed;
    Node<T>* smallest = to_be_removed->right;
    while (smallest->left != nullptr)
    {
        smallest_parent = smallest;
        smallest = smallest->left;
    }

    // smallest contains smallest child in right subtree

    // Move contents, unlink child

    to_be_removed->data = smallest->data;
    if (smallest_parent == to_be_removed)
    {
        smallest_parent->right = smallest->right;
    }
    else
    {
        smallest_parent->left = smallest->right;
    }
}

// INORDER Traversal left, root and right node
template <typename T>
void BinarySearchTree<T>::print(Node<T>* parent) const
{
    if (parent == nullptr)
    {
        return;
    }
    print(parent->left);
    cout << parent->data << ' ' << endl;;
    print(parent->right);
}

template <typename T>
void BinarySearchTree<T>::print() const
{
    print(root);
    cout << endl;
}
template <typename T>
void BinarySearchTree<T>::add_node(Node<T>* parent, Node<T>* new_node) const
{
    if (new_node->data < parent->data)
    {
        if (parent->left == nullptr)
        {
            parent->left = new_node;
        }
        else
        {
            add_node(parent->left, new_node);
        }
    }
    else if (new_node->data > parent->data)
    {
        if (parent->right == nullptr)
        {
            parent->right = new_node;
        }
        else
        {
            add_node(parent->right, new_node);
        }
    }
}
template <typename T>
bool BinarySearchTree<T>::search(const T& element)
{
    Node<T>* current = root;
    while (current != nullptr)
    {
        if (element == current->data)
        {
            return true;
        }
        else if (element < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return false;
}


#endif
