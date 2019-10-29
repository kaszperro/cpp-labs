#include <iostream>
#include <cstring>
#include "List.h"


using namespace std;

template<typename T>
T max(T a, T b, T c) {
    if (a > b && a > c) return a;
    if (b > a && b > c) return b;
    return c;
}

template<>
const char *max<const char *>(const char *a, const char *b, const char *c) {
    if(strcmp(a, b) > 0 && strcmp(a, c) > 0) return a;
    if(strcmp(b, a) > 0 && strcmp(b, c) > 0) return b;
    return c;
}

int main() {
    int a = 1;
    int b = 4;
    int c = 3;

    cout << max(a, b, c) << endl;

    const char sa[] = "ala";
    const char sb[] = "dla";
    const char sc[] = "cla";

    cout << max(sa, sb, sc) << endl;


    List<int> l;
    l.insert(1);
    l.insert(2);
    l.insert(3);

    cout << l << endl;
    l.print();
    cout << endl;

    cout << l.remove() << endl;
    cout << l.remove() << endl;
    cout << l.remove() << endl;

    try {
        cout << l.remove() << endl; //should throw
    } catch (std::invalid_argument& in) {
        cout << "thrown: " << in.what();
    }


    Node<float> n(4);
    n.insert(2);

    cout << n << endl;
    return 0;
}