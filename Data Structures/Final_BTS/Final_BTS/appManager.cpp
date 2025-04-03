#include "appManager.h"

void AppManager::insert(Contact& insertItem)
{
    Node<Contact>* new_node = new Node<Contact>;
    new_node->data = insertItem;
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
bool AppManager::search(const string element)
{
    Node<Contact>* current = root;
    while (current != nullptr)
    {
        if (element == current->data.getFirstName())
        {
            // If found set status to TRUE = FOUND and print some elements of the Contact
            cout << current->data.getFirstName() << " " << current->data.getLastName() << endl;
            return true;
        }
        else if (element < current->data.getFirstName())
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
void AppManager::indOrderTraversal() const
{
    print(root);
    cout << endl;
}
void AppManager::indOrderTraversal(Node<Contact>* parent) const
{

    if (parent == nullptr)
    {
        return;
    }
    print(parent->left);

    cout << parent->data << ' ' << endl;;
    print(parent->right);
}

void AppManager::erase(Contact deleteItem)
{
    // Find node to be removed

    Node<Contact>* to_be_removed = root;
    Node<Contact>* parent = nullptr;
    bool found = false;
    while (!found && to_be_removed != nullptr)
    {
        if (deleteItem.getFirstName() == to_be_removed->data.getFirstName())
        {
            found = true;
        }
        else
        {
            parent = to_be_removed;
            if (deleteItem.getFirstName() < to_be_removed->data.getFirstName())
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
        Node<Contact>* new_child;
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

    Node<Contact>* smallest_parent = to_be_removed;
    Node<Contact>* smallest = to_be_removed->right;
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

