
#include "watervehicles.h"

WaterVehicles::WaterVehicles(std::string name, std::string stamp, const int maxCapacity)
    : TransportBase(std::move(name), std::move(stamp), maxCapacity)
{
}

void WaterVehicles::out() {
    TransportBase::out();
}
