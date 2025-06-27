//
// Created by xqula on 21.06.24.
//

#pragma once

#include "detail.h"

namespace detail {
    enum class TYPE_OF_TRANSMISSION {
        MANUAL = 0,
        AUTOMATIC = 1,
        VARIATION = 2,
        ROBOT = 3
    };

    class Transmission : public Detail {
    public:
        explicit Transmission(
                std::string made,
                std::string name,
                int numberGears,
                TYPE_OF_TRANSMISSION typeOfTransmission);
        auto out_detail() -> void override;
    private:
        int m_numberGears;
        TYPE_OF_TRANSMISSION m_typeOfTransmission;
    };
}