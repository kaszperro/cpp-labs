#include <iostream>

#include "Towar.hpp"
#include "Magazine.hpp"

using namespace std;

int main() {
    //normal constructor
    Magazine m1;

    //copy constructor
    Magazine m2(m1);

    //move constructor
    Magazine m3(std::move(m2));

    //copy assigment
    m2 = m3;

    //move assigment
    m3 = std::move(m2);

    //default constructor
    Towar t1;

    //with parameters
    Towar t2("bulki", 10);

    
    for(int i = 0; i < 5; ++i) {
        m3.add(t2);
    }

    //magazine full

    try {
        m3.add(t1);
    }
    catch(void (*v)(int)) {
        v(12381092);
        cout << "jest void" << endl;
    }
    catch(const int &e) {
        cout << e << endl;
    }
    catch( const std::out_of_range& e ) {
        cout << "Magazine add error: " << e.what() << endl;
    }

    //move m3 to m1
    m1 = std::move(m3);
    cout << m1.get_size() << endl;
    cout << m3.get_size() << endl;

    //move constructor m1 to m4
    Magazine m4(std::move(m1));
    cout << m4.get_size() << endl;
    cout << m1.get_size() << endl;

    //copy construcotr m4 to m5
    Magazine m5(m4);
    cout << m5.get_size() << endl;
    cout << m4.get_size() << endl;


    return 0;
}