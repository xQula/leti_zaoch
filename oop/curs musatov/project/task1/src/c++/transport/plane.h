
#pragma once
#include "transportbase.h"

class Plane : public TransportBase {
public:
    Plane(std::string name, std::string stamp, int maxCapacity);
    ~Plane() override = default;
    auto out() -> void override;

};
