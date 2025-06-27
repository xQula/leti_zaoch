//
// Created by xqula on 21.06.24.
//

#pragma once
#include "car.h"

namespace car{

    enum TYPE_RACING{
        F1 = 0,
        DRIFT = 1,
        RALLY = 2
    };
    class RacingCar: public Car{
    public:
        explicit RacingCar(
                std::string made,
                std::string name,
                std::unique_ptr<detail::Detail> body,
                std::unique_ptr<detail::Detail> engine,
                std::unique_ptr<detail::Detail> transmission,
                std::unique_ptr<detail::Detail> wheel,
                TYPE_RACING typeRacing
        );
        ~RacingCar() override = default;
        auto out_car() -> void override;
    private:
        TYPE_RACING m_typeRacing;
    };

}
