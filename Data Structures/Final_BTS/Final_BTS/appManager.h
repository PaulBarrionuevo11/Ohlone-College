#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#include <iostream>
#include "BST.h"
#include "contact.h"

class AppManager : public BinarySearchTree<Contact>
{
public:

    void insert(Contact& insertItem);
    bool search(const string element);
    void erase(Contact element);
    void indOrderTraversal() const;
    void indOrderTraversal(Node<Contact>* parent) const;

    bool operator=(const Contact& contact);


private:

};

#endif // !APP_MANAGER_H
