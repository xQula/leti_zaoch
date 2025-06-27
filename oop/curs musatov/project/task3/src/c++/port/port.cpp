//
// Created by xqula on 27.06.24.
//

#include "port.h"
#include "../ship/queueship.h"
#include "iostream"


namespace {
    auto typeShipToString(const ship::TYPE_SHIP type) -> std::string {
        if(type == ship::TYPE_SHIP::LITTLE) {
            return "LITTLE";
        } else if(type == ship::TYPE_SHIP::MEDIUM) {
            return "MEDIUM";
        } else {
            return "HIGH";
        }
    }
}
port::Port::Port(QObject *parent)
    : QObject{parent},
      m_timerRepair(std::make_unique<QTimer>(nullptr)),
      m_timerUpDay(std::make_unique<QTimer>(nullptr)),
      m_day(std::make_unique<Day>()),
      m_capacity(std::make_unique<Capacity>()),
      m_queueShipAll(std::make_unique<ship::QueueShip>()),
      m_writer(std::make_unique<utils::Writer>("../output.txt"))

{
    m_timerRepair->setInterval(100);
    m_timerUpDay->setInterval(100);
    m_day->m_maxDay = 7;
    m_capacity->m_maxCapacity = 9;

    connect(m_timerUpDay.get(), &QTimer::timeout, this, [this]() {
        m_day->m_countDay++;
        if(m_day->m_countDay == m_day->m_maxDay) {
            m_day->m_countDay = 0;
            try {
                if(const auto ship = m_queueShipAll->getShip();
                    ship.getCapacity() + m_capacity->m_capacity <= m_capacity->m_maxCapacity && m_shipsQueue.empty()) {
                    m_writer->write("add new ship on pier: " + ship.getName() + " " + typeShipToString(ship.getType()));
                    m_shipsRepair.emplace_back(ship);
                }else {
                    m_writer->write("add new ship on queue: " + ship.getName() + " " + typeShipToString(ship.getType()));
                    m_shipsQueue.emplace_back(ship);
                }
            }catch (std::logic_error &e) {
                m_writer->write(e.what());
            }
        }
    });

    connect(m_timerRepair.get(), &QTimer::timeout, this, [this]() {
        for(const auto &ship : m_shipsRepair) {
            ship.upCountDaysRepair();
            if(ship.isFullRepair()) {
                m_writer->write( "Ship repair: " + ship.getName() + " " +  typeShipToString(ship.getType()));
                m_capacity->m_capacity -= ship.getCapacity();
                std::erase_if(m_shipsRepair, [](const ship::Ship &shipTmp) {
                    return shipTmp.isFullRepair();
                });
                if(m_shipsQueue.empty()) {
                        m_writer->write( "NO SHIPS IN QUEUE");
                        return;
                    }
                if(m_shipsQueue.front().getCapacity() + m_capacity->m_capacity <= m_capacity->m_maxCapacity) {
                    m_writer->write( "add new ship on pier: " + ship.getName() + " " + typeShipToString(m_shipsQueue.front().getType()));
                    m_shipsRepair.emplace_back(m_shipsQueue.front());
                    m_shipsQueue.pop_front();
                }
            }
        }
    });

    m_timerRepair->start();
    m_timerUpDay->start();
}

