//
// Created by xqula on 23.06.24.
//

#pragma once
#include "vector"

namespace core {
    using VecInt = std::vector<int>;
    using Vec2DInt = std::vector<VecInt>;

    class Core {
    public:
        explicit Core();
        auto process() const -> void;
        [[nodiscard]] static auto getShortPath(const Vec2DInt &graph) -> VecInt;

    private:
        Vec2DInt m_tab;
    };
}