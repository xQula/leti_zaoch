#pragma once
#include <deque>
#include "ship.h"

namespace ship{
    class QueueShip {
    public:
        explicit QueueShip();
        auto getShip() -> Ship;
    private:
        std::deque<Ship> m_shipsQueue;
    };
}

