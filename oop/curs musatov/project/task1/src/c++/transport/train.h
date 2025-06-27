
#pragma once
#include "transportbase.h"


class Train : public TransportBase {
public:
    Train(std::string name, std::string stamp, int maxCapacity);
    ~Train() override = default;
    auto out() -> void override;
};

