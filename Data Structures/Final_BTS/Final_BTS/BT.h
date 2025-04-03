#ifndef BinaryTree_H
#define BinaryTree_H

#include <string>

using namespace std;

template <typename T>
class BinaryTree;

template <typename T>
class Node
{
public:
    T data;
    Node* left;
    Node* right;
    friend class BinaryTree<T>;
};

/*
   A binary tree in which each node has two children.
*/
template <typename T>
class BinaryTree
{
public:
    /**
       Constructs an empty tree.
    */
    BinaryTree();

    /**
       Constructs a tree with one node and no children.
       @param root_data the data for the root
    */
    BinaryTree(T root_data);

    /**
       Constructs a binary tree.
       @param root_data the data for the root
       @param left the left subtree
       @param right the right subtree
    */
    BinaryTree(T root_data, BinaryTree left, BinaryTree right);

    /**
       Returns the height of this tree.
       @return the height
    */
    int height() const;

    /**
       Checks whether this tree is empty.
       @return true if this tree is empty
    */
    bool empty() const;

    /**
       Gets the data at the root of this tree.
       @return the root data
    */
    T data() const;

    /**
       Gets the left subtree of this tree.
       @return the left child of the root
    */
    BinaryTree left() const;

    /**
       Gets the right subtree of this tree.
       @return the right child of the root
    */
    BinaryTree right() const;

private:
    /**
       Returns the height of the subtree whose root is the given node.
       @param n a node or nullptr
       @return the height of the subtree, or 0 if n is nullptr
    */
    int height(const Node<T>* n) const;

    Node<T>* root;
};
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}
template <typename T>
BinaryTree<T>::BinaryTree(T root_data)
{
    root = new Node<T>;
    root->data = root_data;
    root->left = nullptr;
    root->right = nullptr;
}
template <typename T>
BinaryTree<T>::BinaryTree(T root_data, BinaryTree<T> left, BinaryTree<T> right)
{
    root = new Node<T>;
    root->data = root_data;
    root->left = left.root;
    root->right = right.root;
}
template <typename T>
int BinaryTree<T>::height(const Node<T>* n) const
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
template <typename T>
int BinaryTree<T>::height() const
{
    return height(root);
}
template <typename T>
bool BinaryTree<T>::empty() const
{
    return root == nullptr;
}
template <typename T>
T BinaryTree<T>::data() const
{
    return root->data;
}
template <typename T>
BinaryTree<T> BinaryTree<T>::left() const
{
    BinaryTree<T> result;
    result.root = root->left;
    return result;
}
template <typename T>
BinaryTree<T> BinaryTree<T>::right() const
{
    BinaryTree<T> result;
    result.root = root->right;
    return result;
}

#endif