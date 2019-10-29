#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <iostream>

class Vector;

class Point {
    private:
        float x, y, z;

    public:
        Point();
        Point(float x, float y, float z);

        Point operator + (const Vector&) const;
        Point &operator ++(); 
        Point operator ++(int); 

        friend std::ostream& operator <<(std::ostream &, const Point &);
};  


class Vector {
    private:
        float x, y, z;
    
    public:
        Vector();
        Vector(float x, float y, float z);
        Vector& operator+=(const Vector&);
        Vector operator +(const Vector&) const;
        Vector operator -() const;
        bool operator > (const Vector &) const;
        
        float& operator[] (int index);

        operator float() const; 

        friend std::ostream & operator << (std::ostream &, const Vector &);
        friend Vector operator *(float, const Vector&);
        friend Vector operator *(const Vector&, float);
        friend Point Point::operator + (const Vector& ) const;
};

#endif
