
#include "passengercar.h"

PassengerCar::PassengerCar(std::string name, std::string stamp, const int maxCapacity)
    : TransportBase(std::move(name), std::move(stamp), maxCapacity)
{
}

void PassengerCar::out() {
    TransportBase::out();
}
