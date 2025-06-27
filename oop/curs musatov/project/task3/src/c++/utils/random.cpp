
#include "random.h"
#include "random"

auto utils::Random::random(const int min, const int max) -> int {
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> dist(min,max); // define the range
    return dist(gen); // generate numbers
}
