#ifndef MAGAZINE_HPP
#define MAGAZINE_HPP

#include <string>
#include "Towar.hpp"

class Magazine {
    public:
        Magazine(unsigned int size=5);
        ~Magazine();

        Magazine(const Magazine&);
        Magazine(Magazine&&);

        Magazine& operator=(Magazine&& );
        Magazine& operator=(const Magazine& );

        Towar& operator[] (int index);

        void add(const Towar& );
        int get_size() const;
        int get_num_elements() const;
    private:
        Towar * tab;
        unsigned int size;
        unsigned int index;
};

#endif