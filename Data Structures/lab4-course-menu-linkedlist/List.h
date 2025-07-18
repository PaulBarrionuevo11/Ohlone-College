#ifndef LIST_H
#define LIST_H

// TODO: Maybe not needed, not doing much
template <typename T>
class List {
public:
    virtual int size() { return len; };
    virtual void insert(T element) = 0;
    virtual int search(T elment) = 0;
    virtual void remove(T element) = 0;
    virtual void print() = 0;

protected:
    int len;
};

#endif