#include "obiekty.hpp"
#include <cmath>

/* ----- Point */

Point::Point() {
    x = y = z = 0;
}

Point::Point(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

std::ostream& operator << (std::ostream &o, const Point &p) {
    return o << "P(" << p.x << ", " << p.y << ", " << p.z << ")";
}

Point Point::operator + (const Vector& v) const{
    return Point(x + v.x, y + v.y, z + v.z);
}

Point &Point::operator++(){
    ++x;
    ++y;
    ++y;
    return *this;
}

Point Point::operator++(int) {
    Point cp = Point(x, y, z);
    ++x;
    ++y;
    ++z;
    return cp;
}


/* ----- Vector */


Vector::Vector() {
    x = y = z = 0;
}

Vector::Vector(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

std::ostream & operator << (std::ostream & o, const Vector & v) {
    return o << "V[" << v.x << ", " << v.y << ", "  << v.z << "]";
}

Vector& Vector::operator+=(const Vector& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector Vector::operator +(const Vector& v) const {
    return Vector(x + v.x, y + v.y, z + v.z);
}

Vector operator *(float f, const Vector& v) {
    return Vector(v.x * f, v.y * f, v.z * f);
}

Vector operator *(const Vector& v, float f) {
    return f*v;
}

Vector Vector::operator -() const {
    return Vector(-x, -y, -z);
}

bool Vector::operator > (const Vector & v) const {
    return (float)(*this) > (float)v;
}

Vector::operator float() const {
    return sqrt(x*x + y*y + z*z);
}

float& Vector::operator [](int index) {
    if(index == 0) return x;
    else if(index == 1) return y;
    else if(index == 2) return z;
    throw std::out_of_range("index should be one of: 0, 1, 2");
}
/*
const float& Vector::operator[] (int index) const {
    if(index == 0) return x;
    else if(index == 1) return y;
    else if(index == 2) return z;
    throw std::out_of_range("index should be one of: 0, 1, 2");
}
*/