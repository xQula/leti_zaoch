#include <iostream>
#include "factory/factorycar.h"

int main() {
    const auto carOne = factory::FactoryCar::createSportCarBMW();
    const auto carTwo = factory::FactoryCar::createSportCarAudi();
    const auto carThree = factory::FactoryCar::createRacingCarFerrari();
    const auto carFour = factory::FactoryCar::createRacingCarMercedes();
    carOne->out_car();
    carTwo->out_car();
    carThree->out_car();
    carFour->out_car();
    return EXIT_SUCCESS;
}
