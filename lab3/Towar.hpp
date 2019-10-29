#ifndef TOWAR_HPP
#define TOWAR_HPP

#include <string>
#include <iostream>

class Towar {
    public:
        Towar(std::string name="Can", float price=1.5);
        friend std::ostream& operator <<(std::ostream &, const Towar&);
    private:
       std::string name;
       float price;
};

#endif