
#pragma once
#include "transportbase.h"

class Bus : public TransportBase{
public:
    Bus(std::string name, std::string stamp, int maxCapacity);
    ~Bus() override = default;
    auto out() -> void override;
};