//
// Created by Kasper Sapała on 2019-04-11.
//

#ifndef LAB4CPP_MANAGER_H
#define LAB4CPP_MANAGER_H

#include "Worker.h"

namespace Company {
    class Manager : public Worker {
    protected:
        double addition;

    public:
        Manager(const std::string &name, const std::string &surname, const Date &born, double salary, double addition);

        Manager() = delete;

        ~Manager() override { std::cout << "Manager destructor\n"; }

        std::string description() const override;

        double payment() const override;

        //bool save(std::ostream &os) const override;

        bool read(std::istream &is) override;

    };

}


#endif //LAB4CPP_MANAGER_H
