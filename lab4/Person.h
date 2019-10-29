//
// Created by Kasper Sapała on 2019-04-11.
//

#ifndef LAB4CPP_PERSON_H
#define LAB4CPP_PERSON_H

#include <iostream>
#include "Date.h"

namespace Company {
    class Person {
    protected:
        std::string name;
        std::string surname;
        Date born;

    public:
        Person(const std::string &name, const std::string &surname, const Date &born);

        Person() = delete;

        virtual ~Person() = default;

        virtual std::string description() const;

        virtual double payment() const = 0;

        virtual bool save(std::ostream &os) const;

        virtual bool read(std::istream &is);
    };

}

#endif //LAB4CPP_PERSON_H
