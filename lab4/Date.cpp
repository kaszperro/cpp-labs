//
// Created by Kasper Sapała on 2019-04-11.
//

#include "Date.h"

namespace Company {
    Date::Date(int year, int month, int day) : day(day), month(month), year(year) {}

    int Date::get_day() const {
        return day;
    }

    void Date::set_day(int day) {
        Date::day = day;
    }

    bool Date::save(std::ostream &os) const {
        os << *this;
        return !os.fail();
    }

    std::ostream &operator<<(std::ostream &os, const Date &d) {
        return os << d.year << "-" << d.month << "-" << d.day;
    }

    bool Date::read(std::istream &is) {
        is >> year >> month >> day;
        return !is.fail();
    }
}

