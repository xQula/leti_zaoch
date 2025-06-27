
#include "plane.h"

Plane::Plane(std::string name, std::string stamp, const int maxCapacity)
    : TransportBase(std::move(name), std::move(stamp), maxCapacity)
{
}

void Plane::out() {
    TransportBase::out();
}
