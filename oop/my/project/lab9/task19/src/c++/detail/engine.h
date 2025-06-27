//
// Created by xqula on 21.06.24.
//

#pragma once

#include "detail.h"

namespace detail {

    class Engine : public Detail {
    public:
        explicit Engine(std::string made, std::string name, int engineCapacity, int m_horsepower);
        auto out_detail() -> void override;
    private:
        int m_engineCapacity;
        int m_horsepower;
    };

}

