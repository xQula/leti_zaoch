//
// Created by xqula on 21.06.24.
//

#include "engine.h"
#include <iostream>

detail::Engine::Engine(std::string made, std::string name, const int engineCapacity, const int m_horsepower):
        Detail(std::move(made), std::move(name)),
        m_engineCapacity(engineCapacity),
        m_horsepower(m_horsepower)
{

}

auto detail::Engine::out_detail() -> void {
    std::cout << "**********************" << std::endl;
    Detail::out_detail();
    std::cout << "Engine capacity: " << m_engineCapacity << std::endl;
    std::cout << "Horsepower: " << m_horsepower << std::endl;
    std::cout << "**********************" << std::endl;
}
