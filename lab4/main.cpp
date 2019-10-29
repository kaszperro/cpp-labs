#include <iostream>

#include "Date.h"
#include "Worker.h"
#include "Manager.h"
#include "Intern.h"

using namespace std;
using namespace Company;

int main() {
    Date d(2017, 1, 1);
    cout << d << endl;
    d.save(cout);
    Worker w1("Kasper", "sap", d, 10);

    //w1.save(cout);
    //w1.read(cin);
    //w1.save(cout);

    Person *tab[10];

    tab[0] = new Worker("Dominik", "Mondzik", Date(1997, 1, 2), 100);
    tab[1] = new Manager("Kasper", "Sapala", Date(1997, 10, 24), 100, 200);
    tab[2] = new Intern("Maciej", "Sopata", Date(1997, 7, 7), 123, Date(2019, 9, 9));
    for (int i = 0; i < 3; ++i) {

        cout << "description: ";
        tab[i]->save(cout);
        cout << " payment: " << tab[i]->payment() << "\n";

        tab[i]->read(cin);

        cout << "description: ";
        tab[i]->save(cout);
        cout << " payment: " << tab[i]->payment() << "\n";

        delete tab[i];
    }



    return 0;
}