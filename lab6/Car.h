#include <utility>

//
// Created by Kasper Sapała on 2019-06-06.
//

#ifndef LAB6_CAR_H
#define LAB6_CAR_H

#include <iostream>

class Car {
private:
    std::string type;
    double capacity;
    int year;

    std::string get_random_type();

    double get_random_capacity();

    int get_random_year();

public:
    friend std::ostream &operator<<(std::ostream &stream, const Car &c) {
        stream << "C:[" << c.type << " " << c.capacity << " " << c.year << "]";
        return stream;
    }


    Car(std::string type, double capacity, int year) : type(std::move(type)), capacity(capacity), year(year) {}

    Car() : type(get_random_type()), capacity(get_random_capacity()), year(get_random_year()) {}

    bool operator<(const Car &other) const {
        return get_key() < other.get_key();
    }

    double get_key() const {
        return year + capacity;
    }

    bool operator == (int year) const {
        return this->year == year;
    }

    int get_year() const {return year;}
    void set_year(int year) { this->year = year; }

    double get_capacity() const { return capacity; }

    std::string get_type() const { return type; }

    static Car generator();

};


#endif //LAB6_CAR_H
