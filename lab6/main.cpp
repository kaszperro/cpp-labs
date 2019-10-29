#include <iostream>
#include <vector>
#include <map>
#include <set>

#include "Car.h"


using namespace std;

int main() {

    const int size = 5;


    vector<Car> v_car;
    set<Car> s_car;
    map<double, Car> m_car;


    v_car.reserve(size);
    for (int i = 0; i < size - 1; ++i) {
        v_car.emplace_back();
    }

    v_car.push_back(*v_car.begin());

    for (auto it = v_car.begin(); it != v_car.end(); ++it) {
        cout << "vector: " << *it << endl;
    }

    for (auto const &c : v_car) {
        if (!s_car.insert(c).second) {
            cout << "set duplicate: " << c << endl;
        }
    }

    for (auto &c : v_car) {
        m_car[c.get_key()] = c;
    }

    for (auto const&[key, val] : m_car) {
        cout << "map[" << key << "]: " << val << endl;
    }


    vector<Car> gen(10);
    generate(gen.begin(), gen.end(), Car::generator);

    int i = 2001;
    for (auto &c : gen) {
        c.set_year(i++);
    }

    for (auto const &c : gen) {
        cout << "gen: " << c << endl;
    }
/*
    auto find_result = std::find_if(gen.begin(), gen.end(),
                                    [](const Car &c) { return c.get_year() == 2005; });*/

    auto find_result = find(gen.begin(), gen.end(), 2005);

    if (find_result != gen.end()) {
        cout << "find: " << *find_result << endl;
    } else {
        cout << "find: no results" << endl;
    }


    string type;
    cin >> type;

    long num_items = std::count_if(
            gen.begin(),
            gen.end(),
            [type](const Car &c) { return c.get_type() == type; }
    );

    cout << "found " << num_items << " cars with type: " << type << endl;

    std::sort(gen.begin(), gen.end(), [](const Car &a, const Car &b) {
        if (a.get_year() != b.get_year()) {
            return a.get_year() < b.get_year();
        }
        return a.get_capacity() < b.get_capacity();
    });
    cout << "AFTER SORT" << endl;
    for (const auto &c: gen) {
        cout << c << endl;
    }

    std::sort(gen.begin(), gen.end(), [](const Car &a, const Car &b){
        return a.get_type() < b.get_type();
    });

    auto
    to_remove = std::unique(
            gen.begin(),
            gen.end(),
            [](const Car &a, const Car &b) {
                return a.get_type() == b.get_type();
            }
    );

    gen.erase(to_remove, gen.end());

    cout << "UNIQUE TYPES" << endl;
    for (const auto &c: gen) {
        cout << c << endl;
    }


    return 0;
}