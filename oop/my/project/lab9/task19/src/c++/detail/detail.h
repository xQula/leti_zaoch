//
// Created by xqula on 21.06.24.
//

#pragma once

#include "string"

namespace detail {

    class Detail {
    public:
        explicit Detail(std::string made, std::string name);
        virtual ~Detail() = default;
        virtual auto out_detail() -> void;

    private:
        std::string m_made;
        std::string m_name;
    };
}


