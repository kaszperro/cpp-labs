//
// Created by Kasper Sapała on 2019-04-11.
//

#include "Manager.h"
#include <sstream>

namespace Company {
    Manager::Manager(const std::string &name, const std::string &surname, const Company::Date &born, double salary,
                     double addition) : Worker(name, surname, born, salary), addition(addition) {}

    std::string Manager::description() const {
        std::stringstream st;
        st << Worker::description() << " addition: " << addition;
        return st.str();

    }

    double Manager::payment() const {
        return Worker::payment() + addition;
    }

    /*
    bool Manager::save(std::ostream &os) const {
        os << description();
        return !os.fail();
    }
     */

    bool Manager::read(std::istream &is) {
        Worker::read(is);
        is >> addition;
        return !is.fail();
    }
}

