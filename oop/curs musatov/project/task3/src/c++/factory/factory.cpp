#include "factory.h"
#include "utils/random.h"

auto factory::Factory::createLowShip() -> ship::Ship {
    return {5, 3, ship::TYPE_SHIP::LITTLE, std::to_string(utils::Random::random(1, 100))};
}

auto factory::Factory::createMediumShip() -> ship::Ship {
    return {10, 6, ship::TYPE_SHIP::MEDIUM, std::to_string(utils::Random::random(1, 100))};
}

auto factory::Factory::createHighShip() -> ship::Ship{
    return {15, 9, ship::TYPE_SHIP::HIGH, std::to_string(utils::Random::random(1, 100))};
}
