#include "Towar.hpp"

Towar::Towar(std::string name, float price) {
    this->name = name;
    this->price = price;
}

std::ostream & operator << (std::ostream & o, const Towar & t) {
    return o << "T[name: " << t.name << ", price: " << t.price << "]";
}