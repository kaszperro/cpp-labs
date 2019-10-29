#include <iostream>
#include "obiekty.hpp"

using namespace std;

int main() {
    Vector v1(1, 2, 3);
    Point p1(1, 2, 3);

    //v1[0] = 10;

    cout << (p1 + v1) << endl;

    cout << (-v1) << endl;

   // cout << v1[2] << endl;

    cout << (p1++) << p1 << (++p1) << endl;

    cout << (v1 * 4.0f) << " " << (4.0f * v1)<< endl;

    Vector v2(10, 10, 10);

    cout << (v1 > v2) << endl;
    cout << (v2 > v1) << endl;

    return 0;
}