//
// Created by xqula on 21.06.24.
//

#pragma once

#include "car.h"

namespace car {

    class SportCar: public Car {

    public:
        explicit SportCar(
                std::string made,
                std::string name,
                std::unique_ptr<detail::Detail> body,
                std::unique_ptr<detail::Detail> engine,
                std::unique_ptr<detail::Detail> transmission,
                std::unique_ptr<detail::Detail> wheel,
                bool isNitro
        );
        ~SportCar() override = default;
        auto out_car() -> void override;
    private:
        bool m_isNitro;
    };

}