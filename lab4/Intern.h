//
// Created by Kasper Sapała on 2019-04-11.
//

#ifndef LAB4CPP_INTERN_H
#define LAB4CPP_INTERN_H

#include "Person.h"
#include "Date.h"

namespace Company {
    class Intern : public Person {
    protected:
        double scholarship;
        Date inter_end_date;
    public:
        Intern(const std::string &name, const std::string &surname, const Date &born, double scholarship,
               const Date &inter_end_date);

        Intern() = delete;

        void set_inter_end_date(const Date &inter_end_date);


        std::string description() const override;

        double payment() const override;

       // bool save(std::ostream &os) const override;

        bool read(std::istream &is) override;
    };
}


#endif //LAB4CPP_INTERN_H
