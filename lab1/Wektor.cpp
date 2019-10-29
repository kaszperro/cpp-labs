#include "Wektor.hpp"
#include <iomanip>

int Wektor::precision = 3;

Wektor::Wektor() {
    vx = vy = vz = 1.0;
}

Wektor::Wektor(double vx, double vy, double vz) {
    this->vx = vx;
    this->vy = vy;
    this->vz = vz;
}

double Wektor::get_vx() {
    return vx;
}

void Wektor::set_vx(double vx) {
    this->vx = vx;
}

double Wektor::dot(const Wektor & other) {
    return vx * other.vx + vy * other.vy + vz * other.vz;
}

void Wektor::write() {
    save(std::cout);
}

void Wektor::set_precision(int prec) {
     precision = prec;
}

void Wektor::save(std::ostream &os) {
    os << std::setprecision(Wektor::precision)
    << std::fixed << "[" << vx << "; "  << vy << "; " <<  vz << "]\n";
}

void Wektor::read(std::istream &is) {
    char dummy;
    is >> dummy >> vx >> dummy >> vy >> dummy >> vz >> dummy;
}