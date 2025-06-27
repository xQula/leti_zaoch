
#include "transportbase.h"
#include <iostream>
#include <utility>

TransportBase::TransportBase(std::string name, std::string stamp, const int maxCapacity) :
    m_name(std::move(name)), m_stamp(std::move(stamp)), m_maxCapacity(maxCapacity)
{
}

auto TransportBase::out() -> void {
    std::cout << "----------------" << std::endl;
    std::cout << "Transport name: " << m_name << std::endl
              << "Stamp: " << m_stamp << std::endl
              << "Max capacity: " << m_maxCapacity << std::endl;
    std::cout << "----------------" << std::endl;
}
