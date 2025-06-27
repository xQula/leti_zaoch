//
// Created by xqula on 27.06.24.
//

#include "ship.h"

ship::Ship::Ship(int daysRepair, int capacity, const TYPE_SHIP type, const std::string &name)
    : m_logbook(std::make_shared<Logbook>(daysRepair, 0, capacity)),
      m_type(type),
      m_name(std::move("SHIP " + name))
{
}

auto ship::Ship::upCountDaysRepair() const -> void {
    m_logbook->m_countDeysRepair++;
}

auto ship::Ship::resetCountDaysRepair() const -> void {
    m_logbook->m_countDeysRepair = 0;
}

auto ship::Ship::isFullRepair() const -> bool {
    return m_logbook->m_countDeysRepair >= m_logbook->m_daysRepair;
}

auto ship::Ship::getCapacity() const -> int {
    return m_logbook->m_capacity;
}

auto ship::Ship::getType() const -> TYPE_SHIP {
    return m_type;
}

auto ship::Ship::getName() const -> std::string {
    return m_name;
}
