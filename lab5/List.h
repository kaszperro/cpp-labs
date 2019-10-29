//
// Created by Kasper Sapała on 2019-05-30.
//

#ifndef LAB5_LIST_H
#define LAB5_LIST_H

#include <memory>
#include <iostream>

#include "Node.h"


template<typename T>
class List {
    std::unique_ptr<Node<T>> head;


public:
    List() : head(nullptr) {}

    List(const List &) = delete;

    List &operator=(const List &) = delete;


    bool insert(T val);

    T remove();

    void print() const;

    template<typename U>
    friend std::ostream &operator<<(std::ostream &, const List<U> &);

};


template<typename T>
bool List<T>::insert(T val) {
    if (head == nullptr) {
        head = std::make_unique<Node<T>>(val);
        return true;
    }
    return head->insert(val);
}

template<typename T>
T List<T>::remove() {
    if (head == nullptr) {
        throw std::invalid_argument("list is empty");
    }
    T tmp = head->data;
    head = std::move(head->next);
    return tmp;
}

template<typename T>
void List<T>::print() const {
    std::cout << *this;
    /*
    std::cout << "List: [";
    if (head != nullptr)
        head->print();
    std::cout << "]";*/
}

template<typename U>
std::ostream &operator<<(std::ostream &o, const List<U> &t) {
    if (t.head == nullptr) {
        o << "empty list";
        return o;
    }

    o << "List: [";
    if (t.head != nullptr)
        o << *t.head;

    o << "]";
    return o;
}


#endif //LAB5_LIST_H
