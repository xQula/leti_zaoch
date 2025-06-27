
#pragma once
#include "transportbase.h"

class WaterVehicles : TransportBase {
public:
    WaterVehicles(std::string name, std::string stamp, int maxCapacity);
    ~WaterVehicles() override = default;
    auto out() -> void override;
};

