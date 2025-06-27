//
// Created by xqula on 21.06.24.
//

#pragma once
#include "memory"
#include "car/car.h"

namespace factory {

    class FactoryCar {
    public:
        FactoryCar() = default;

        virtual ~FactoryCar() = default;

        static auto createSportCarBMW() -> std::unique_ptr<car::Car>;

        static auto createSportCarAudi() -> std::unique_ptr<car::Car>;

        static auto createRacingCarFerrari() -> std::unique_ptr<car::Car>;

        static auto createRacingCarMercedes() -> std::unique_ptr<car::Car>;
    };

}
