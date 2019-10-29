#ifndef WEKTOR_H
#define WEKTOR_H

#include <iostream>

class Wektor {
    private:
        double vx, vz, vy;
        static int precision;
    public:
        Wektor();
        Wektor(double vx, double vy=1.0, double vz=1.0);
        double get_vx();
        void set_vx(double vx);
        double dot(const Wektor &other);
        void write();
        static void set_precision(int prec);
        void save(std::ostream& os);
        void read(std::istream& is);
};

#endif