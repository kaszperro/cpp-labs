//
// Created by Kasper Sapała on 2019-04-11.
//

#include "Intern.h"

#include <sstream>

namespace Company {
    Intern::Intern(const std::string &name, const std::string &surname, const Date &born,
                   double scholarship, const Date &inter_end_date) : Person(name, surname, born),
                                                                     scholarship(scholarship),
                                                                     inter_end_date(inter_end_date) {}

    void Intern::set_inter_end_date(const Date &inter_end_date) {
        Intern::inter_end_date = inter_end_date;
    }

    std::string Intern::description() const {
        std::stringstream st;
        st << Person::description();
        st << " scholarship: " << scholarship << " end date: " << inter_end_date;
        return st.str();
    }

    /*
    bool Intern::save(std::ostream &os) const {
        os << description();
        return !os.fail();
    }
     */

    bool Intern::read(std::istream &is) {
        Person::read(is);
        is >> scholarship;
        return inter_end_date.read(is);

    }

    double Intern::payment() const {
        return scholarship;
    }

}
