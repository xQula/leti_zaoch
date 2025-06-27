//
// Created by xqula on 21.06.24.
//

#include "detail.h"

#include <utility>
#include "iostream"

detail::Detail::Detail(std::string made, std::string name) : m_made(std::move(made)), m_name(std::move(name)) {}

auto detail::Detail::out_detail() -> void {
    std::cout << "Detail made: " << m_made << "\nDetail name: " << m_name << std::endl;
}
