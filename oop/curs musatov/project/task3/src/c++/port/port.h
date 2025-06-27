#pragma once
#include "ship/ship.h"
#include "ship/queueship.h"
#include "utils/writer.h"
#include "deque"
#include "vector"
#include "memory"
#include "QTimer"
#include "QObject"


namespace port {
    struct Day {
        int m_maxDay;
        int m_countDay;
    };
    struct Capacity {
        int m_capacity;
        int m_maxCapacity;
    };
    class Port final : QObject {
     Q_OBJECT
    public:
     explicit Port(QObject *parent = nullptr);
    private:
        std::vector<ship::Ship> m_shipsRepair;
        std::deque<ship::Ship> m_shipsQueue;
        std::unique_ptr<QTimer> m_timerRepair;
        std::unique_ptr<QTimer> m_timerUpDay;
        std::unique_ptr<Day> m_day;
        std::unique_ptr<Capacity> m_capacity;
        std::unique_ptr<ship::QueueShip> m_queueShipAll;
        std::unique_ptr<utils::Writer> m_writer;
    };
}


