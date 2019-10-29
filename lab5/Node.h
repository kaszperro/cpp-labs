//
// Created by Kasper Sapała on 2019-05-30.
//

#ifndef LAB5_NODE_H
#define LAB5_NODE_H

template<typename T>
class List;

template<typename T>
class Node {
    T data;
    std::unique_ptr<Node> next;

public:
    explicit Node(T _data) : data(_data), next(nullptr) {}


    Node(const Node &) = delete;

    Node &operator=(const Node &) = delete;

    bool insert(T val);

    void print() const;

    template<typename U>
    friend std::ostream &operator<<(std::ostream &, const Node<U> &);

    friend class List<T>;

};

template<typename T>
bool Node<T>::insert(T val) {
    if (next == nullptr) {
        next = std::make_unique<Node<T>>(val);
        return true;
    } else {
        return next->insert(val);
    }
}

template<typename T>
void Node<T>::print() const {
    std::cout << *this;
    /*
    std::cout << data;
    if (next != nullptr) {
        std::cout << " ";
        next->print();
    }*/
}


template<typename U>
std::ostream &operator<<(std::ostream &o, const Node<U> &t) {
    o << t.data;
    if (t.next != nullptr) {
        o << " " << *t.next;
    }
    return o;
}

#endif //LAB5_NODE_H
