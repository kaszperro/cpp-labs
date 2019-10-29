//
// Created by Kasper Sapała on 2019-04-11.
//

#include "Person.h"
#include <sstream>
namespace Company {
    Person::Person(const std::string &name, const std::string &surname, const Date &born) : name(name),
                                                                                            surname(surname),
                                                                                            born(born) {}

    std::string Person::description() const {
        std::stringstream st;
        st << "born on: " << born << " name: " << name << " surname: " << surname;
        return st.str();
    }

    bool Person::save(std::ostream &os) const {
        os << description();
        return !os.fail();
    }

    bool Person::read(std::istream &is) {
        is >> name >> surname;
        born.read(is);

        return !is.fail();
    }

}
