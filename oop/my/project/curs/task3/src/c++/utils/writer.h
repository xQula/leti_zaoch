//
// Created by xqula on 24.06.24.
//

#pragma once
#include "string"

namespace utils {
    class Writer {
    public:
        explicit Writer(std::string name);
        ~Writer() = default;
        auto write(std::string_view txt) const -> void;

    private:
        std::string m_name;
    };
}

