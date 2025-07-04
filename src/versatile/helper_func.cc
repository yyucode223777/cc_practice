#include <random>

#include "../../include/versatile/helper_func.h"

int HelperFunc::getRandomNumber(int range) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, range - 1);

    return distrib(gen);
}