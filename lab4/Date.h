//
// Created by Kasper Sapała on 2019-04-11.
//

#ifndef LAB4CPP_DATE_H
#define LAB4CPP_DATE_H

#include <iostream>

namespace Company {
    class Date {
    private:
        int year;
        int month;
        int day;

    public:
        Date() = delete;

        Date(int year, int month, int day);

        int get_day() const;

        void set_day(int day);

        bool save(std::ostream &os) const;

        bool read(std::istream &is);

        friend std::ostream &operator<<(std::ostream &os, const Date &d);
    };
};


#endif //LAB4CPP_DATE_H
