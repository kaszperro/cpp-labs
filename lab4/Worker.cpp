//
// Created by Kasper Sapała on 2019-04-11.
//

#include "Worker.h"
#include <sstream>

namespace Company {
    Worker::Worker(const std::string &name, const std::string &surname, const Company::Date &born, double salary)
            : Person(name, surname, born), salary(salary) {}

    std::string Worker::description() const {
        std::stringstream st;
        st << Person::description() << " salary: " << salary;
        return st.str();
    }

    /*
    bool Worker::save(std::ostream &os) const {
        os << description();
        return !os.fail();
    }
     */

    bool Worker::read(std::istream &is) {
        Person::read(is);
        is >> salary;
        return !is.fail();
    }

    double Worker::payment() const {
        return salary;
    }
}
