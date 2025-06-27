#pragma once

#include "factory/factory.h"
#include "ship/ship.h"

namespace factory {
    class Factory {
    public:
        static auto createLowShip() -> ship::Ship;

        static auto createMediumShip() -> ship::Ship;

        static auto createHighShip() -> ship::Ship;
    };
}
