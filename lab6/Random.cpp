//
// Created by Kasper Sapała on 2019-06-06.
//

#include "Random.h"
#include <random>

float Random::random_float(float a, float b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(a, b);
    return dis(gen);
}

int Random::random_int(int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(a, b);
    return dis(gen);
}
