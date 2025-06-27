//
// Created by dokto on 10.06.2024.
//
#pragma once

#include "string"

namespace handler {
    class HandlerString {
    public:
        auto operator() () -> void;
    private:
        auto input_name() -> void;
        auto output_name() const -> void;
        std::string m_name;
    };
}

