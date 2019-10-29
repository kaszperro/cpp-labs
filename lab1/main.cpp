#include "Wektor.hpp"
#include <iostream>

using namespace std;

int main () {
    Wektor w1(1,2, 3);
    w1.write();

    Wektor w2(3, 4, 5);
    w2.write();

    Wektor w3;
   // w3.read(cin);
    Wektor::set_precision(10);
    w3.write();

    double d = w1.dot(w2);
    cout << d << endl;
    return 0;
}