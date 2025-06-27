//
// Created by xqula on 24.06.24.
//

#include "writer.h"
#include <fstream>
#include <utility>

utils::Writer::Writer(std::string name) : m_name(std::move(name)) {}

auto utils::Writer::write(const std::string_view txt) const -> void {
    std::ofstream out;
    out.open(m_name, std::ios_base::app);
    if (out.is_open())
    {
        out << txt << std::endl;
    }else {
        throw std::runtime_error("Can't open file" + m_name);
    }
    out.close();
}

