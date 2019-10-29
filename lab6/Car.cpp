//
// Created by Kasper Sapała on 2019-06-06.
//

#include "Car.h"
#include "Random.h"

#include <vector>

std::string Car::get_random_type() {
    static const std::vector<std::string> types {
            "fiat", "porsche", "bmw", "mercedes"
    };
    return types[Random::random_int(0, static_cast<int>(types.size() - 1))];
}

double Car::get_random_capacity() {
    static const std::vector<double> capacities {
            100, 200, 350
    };
    return capacities[Random::random_int(0, static_cast<int>(capacities.size() - 1))];
}

int Car::get_random_year() {
    return Random::random_int(2000, 2014);
}

Car Car::generator() {
    return Car();
}
