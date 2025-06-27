

#pragma once
#include "transportbase.h"

class PassengerCar : public TransportBase {
public:
    PassengerCar(std::string name, std::string stamp, int maxCapacity);
    ~PassengerCar() override = default;
    auto out() -> void override;
};
