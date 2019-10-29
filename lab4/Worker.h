//
// Created by Kasper Sapała on 2019-04-11.
//

#ifndef LAB4CPP_WORKER_H
#define LAB4CPP_WORKER_H

#include "Person.h"

namespace Company {
    class Worker: public Person {
    protected:
    double salary;
    public:
        Worker(const std::string &name, const std::string &surname, const Date &born, double salary);
        Worker() = delete;

        std::string description() const override;

        double payment() const override;

       // bool save(std::ostream &os) const override;

        bool read(std::istream &is) override;
    };
}


#endif //LAB4CPP_WORKER_H
