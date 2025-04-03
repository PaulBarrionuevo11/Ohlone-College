#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>

using namespace std;

template<typename T>
class Binary_tree;

template<typename T>
class Node {
private:
    T data;
    Node* left;
    Node* right;
    friend class Binary_tree<T>;
};

/*
   A binary tree in which each node has two children.
*/
template<typename T>
class Binary_tree {
public:

    Binary_tree();
    Binary_tree(T root_data);

    Binary_tree(T root_data, Binary_tree<T> left, Binary_tree<T> right);
    int height() const;
    bool empty() const;
    T data() const;
    Binary_tree<T> right() const;
    int count_nodes_with_one_child() const;
    int count_nodes_with_one_child(Node<T>*) const;
    void swap_children(Node* <T> n);
    void swap_children();

private:

    int height(const Node<T>* n) const;
    Node<T>* root;
};
template<typename T>
Binary_tree<T>::Binary_tree()
{
    root = nullptr;
}
template<typename T>
Binary_tree<T>::Binary_tree(T root_data)
{
    root = new Node<T>;
    root->data = root_data;
    root->left = nullptr;
    root->right = nullptr;
}
template<typename T>
Binary_tree<T>::Binary_tree(T root_data, Binary_tree<T> left, Binary_tree<T> right)
{
    root = new Node<T>;
    root->data = root_data;
    root->left = left.root;
    root->right = right.root;
}
template<typename T>
int Binary_tree<T>::height(const Node<T>* n) const
{
    if (n == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + max(height(n->left), height(n->right));
    }
}
template<typename T>
int Binary_tree<T>::height() const
{
    return height(root);
}
template<typename T>
bool Binary_tree<T>::empty() const
{
    return root == nullptr;
}
template<typename T>
T Binary_tree<T>::data() const
{
    return root->data;
}
template<typename T>
Binary_tree<T> Binary_tree<T>::right() const
{
    Binary_tree<T> result;
    result.root = root->right;
    return result;
}
template<typename T>
int Binary_tree<T>::count_nodes_with_one_child(Node<T>* n) const
{
    if (n == nullptr)
    {
        return 0;
    }

    int sum = ((n->left == nullptr) + (n->right == nullptr)) % 2;
    return sum + count_nodes_with_one_child(n->left)
        + count_nodes_with_one_child(n->right);


}
template<typename T>
int Binary_tree<T>::count_nodes_with_one_child() const
{
    return count_nodes_with_one_child(root);
}

/**
     Swap the children of a tree rooted at n
     @return the tree with the children rotated
*/
template <typename T>
void Binary_tree<T>::swap_children(Node<T>* n) {
    if (n == nullptr) {
        return;
    }

    // Swap the left and right pointers
    Node<T>* temp = n->left;
    n->left = n->right;
    n->right = temp;

    // Recursively swap the children of the left and right nodes
    swap_children(n->left);
    swap_children(n->right);
}

/**
   Swap the children of the entire tree
*/
template <typename T>
void Binary_tree<T>::swap_children() {
    swap_children(root);
}

#endif