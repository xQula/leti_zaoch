
#include "bus.h"

Bus::Bus(std::string name, std::string stamp, const int maxCapacity)
    : TransportBase(std::move(name), std::move(stamp), maxCapacity)
{
}

void Bus::out() {
    TransportBase::out();
}
