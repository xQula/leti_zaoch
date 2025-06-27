
#include "train.h"

Train::Train(std::string name, std::string stamp, const int maxCapacity)
    : TransportBase(std::move(name), std::move(stamp), maxCapacity)
{
}

void Train::out() {
    TransportBase::out();
}
