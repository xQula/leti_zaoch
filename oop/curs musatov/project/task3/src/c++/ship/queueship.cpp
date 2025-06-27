//
// Created by xqula on 27.06.24.
//

#include "queueship.h"
#include "../factory/factory.h"
#include "../utils/random.h"

namespace {

    auto createShip(
        int &countShip,
        const int maxCountChip,
        const ship::TYPE_SHIP type,
        std::deque<ship::Ship> &shipsQueue,
        bool &isAdd)
        -> void
    {
        if(countShip < maxCountChip) {
            if(type == ship::TYPE_SHIP::LITTLE) {
                shipsQueue.push_back(factory::Factory::createLowShip());
            }else if(type == ship::TYPE_SHIP::MEDIUM) {
                shipsQueue.push_back(factory::Factory::createMediumShip());
            }else {
                shipsQueue.push_back(factory::Factory::createHighShip());
            }
            countShip++;
            isAdd = true;
        }
    }

    auto createQueueShip() -> std::deque<ship::Ship> {
        std::deque<ship::Ship> shipsQueue;
        constexpr int maxShips = 50;
        constexpr int maxLittleShip = maxShips * 0.6;
        constexpr int maxMediumShip = maxShips * 0.3;
        constexpr int maxHighShip = maxShips * 0.1;
        int countLittleShip = 0;
        int countMediumShip = 0;
        int countHighShip = 0;
        for(int i = 0; i < maxShips; i++) {
            bool isAdd = false;
            if(const int randNum = utils::Random::random(1, 3);
                randNum == 1)
            {
                createShip(
                    countLittleShip,
                    maxLittleShip,
                    ship::TYPE_SHIP::LITTLE,
                    shipsQueue,
                    isAdd);
            } else if(randNum == 2) {
                createShip(
                    countMediumShip,
                    maxMediumShip,
                    ship::TYPE_SHIP::MEDIUM,
                    shipsQueue,
                    isAdd);
            } else if(randNum == 3) {
                createShip(
                    countHighShip,
                    maxHighShip,
                    ship::TYPE_SHIP::HIGH,
                    shipsQueue,
                    isAdd);
            }
            if(not isAdd) {
                createShip(
                    countLittleShip,
                    maxLittleShip,
                    ship::TYPE_SHIP::LITTLE,
                    shipsQueue,
                    isAdd);
                if(isAdd) continue;
                createShip(
                    countMediumShip,
                    maxMediumShip,
                    ship::TYPE_SHIP::MEDIUM,
                    shipsQueue,
                    isAdd);
                if(isAdd) continue;
                createShip(
                    countHighShip,
                    maxHighShip,
                    ship::TYPE_SHIP::HIGH,
                    shipsQueue,
                    isAdd);
            }
        }
        return shipsQueue;
    }
}

ship::QueueShip::QueueShip():
    m_shipsQueue(createQueueShip())
{
}

auto ship::QueueShip::getShip() -> Ship {
    if(m_shipsQueue.empty()) {
        throw std::logic_error("NO SHIPS IN QUEUE");
    }
    const auto ship = m_shipsQueue.front();
    m_shipsQueue.pop_front();
    return ship;
}
