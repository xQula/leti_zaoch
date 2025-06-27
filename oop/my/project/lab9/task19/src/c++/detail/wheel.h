//
// Created by xqula on 21.06.24.
//

#pragma once

#include "detail.h"

namespace detail {
    enum class SPEED_INDEX {
        P = 150,
        Q = 160,
        R = 170,
        S = 180,
        T = 190,
        U = 200,
        H = 210,
        V = 240,
        W = 270,
        Y = 300
    };

    class Wheel: public Detail {
    public:
        explicit Wheel( std::string made,
                        std::string name,
                        int diameterDisc,
                        int loadIndex,
                        detail::SPEED_INDEX speedIndex);
        auto out_detail() -> void override;
    private:
        int m_diameterDisc{};
        int m_loadIndex{};
        SPEED_INDEX m_speedIndex;
    };

}