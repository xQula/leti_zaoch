//
// Created by xqula on 21.06.24.
//

#pragma once

#include "string"
#include "detail/detail.h"
#include "memory"

namespace car {

    class Car {
    public:
        explicit Car(
                std::string made,
                std::string name,
                std::unique_ptr<detail::Detail> body,
                std::unique_ptr<detail::Detail> engine,
                std::unique_ptr<detail::Detail> transmission,
                std::unique_ptr<detail::Detail> wheel);
        virtual ~Car() = default;
        virtual auto out_car() -> void;
    private:
        std::string m_made;
        std::string m_name;
        std::unique_ptr<detail::Detail> m_body;
        std::unique_ptr<detail::Detail> m_engine;
        std::unique_ptr<detail::Detail> m_transmission;
        std::unique_ptr<detail::Detail> m_wheel;
    };

}


