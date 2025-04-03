#ifndef A_ARRAY_LIST_H
#define A_ARRAY_LIST_H
#include "List.h"

template <typename T>
class AbstractArrayList : public List<T> {
public:
    virtual void insert(T element) = 0;
    virtual void sort() = 0;
    virtual int search(T elment) = 0;
    virtual void remove(T element) = 0;


    // specific to erase an element at index
    virtual T& at(int k) const = 0;
    virtual void removeAt(int k) = 0;
    virtual void insert(int k, T element) = 0;

    virtual void print() const = 0;



};

#endif