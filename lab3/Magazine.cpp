#include "Magazine.hpp"
#include <algorithm>

Magazine::Magazine(unsigned int size) {
    this->size = size;
    this->index = 0;
    tab = new Towar[size];
}


Magazine::~Magazine(){
    delete [] tab;
}


Magazine::Magazine(const Magazine& m):size{m.size}, index{m.index}, tab{ new Towar[m.size] } {
    std::cout << "copy constructor &\n";
    std::copy(m.tab, m.tab+size, tab);
}

Magazine::Magazine(Magazine&& m):size{m.size}, index{m.index}, tab{ m.tab } {
    std::cout << "move constructor &&\n";
    m.tab = NULL;
    m.size = 0;
    m.index = 0;
}

void f(int a) {
    std::cout << a << std::endl;
}

void Magazine::add(const Towar& t) {
    if(index >= size)
        throw std::out_of_range("array is full"); //f jest spoko
    tab[index++] = t;
}

int Magazine::get_size() const {
    return size;
}

int Magazine::get_num_elements() const {
    return index;
}

Towar& Magazine::operator[] (int index) {
    if(index >= size || index >= this->index)
        throw std::out_of_range("index out of range");

    return tab[index];
}

Magazine& Magazine::operator=(Magazine&& m) {
    std::cout << "= &&\n";
    if(&m != this) {
        delete [] tab;
        tab = m.tab;
        size = m.size;
        index = m.index;

        m.tab = NULL;
        m.size = 0;
        m.index = 0;
    }
    return *this;
}

Magazine& Magazine::operator=(const Magazine& m) {
    std::cout << "= &\n";
     if(&m != this) {
        delete [] tab;
        size = m.size;
        index = m.index;
        tab = new Towar[size];
        std::copy(m.tab, m.tab+size, tab);
    }
    return *this;
}