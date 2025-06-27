//
// Created by xqula on 21.06.24.
//

#include "car.h"
#include "iostream"

car::Car::Car(std::string made,
              std::string name,
              std::unique_ptr<detail::Detail> body,
              std::unique_ptr<detail::Detail> engine,
              std::unique_ptr<detail::Detail> transmission,
              std::unique_ptr<detail::Detail> wheel):
    m_made(std::move(made)),
    m_name(std::move(name)),
    m_body(std::move(body)),
    m_engine(std::move(engine)),
    m_transmission(std::move(transmission)),
    m_wheel(std::move(wheel))
{
}

auto car::Car::out_car() -> void {
    std::cout << "Made: " << m_made << std::endl;
    std::cout << "Name: " << m_name << std::endl;
    m_body->out_detail();
    m_engine->out_detail();
    m_transmission->out_detail();
    m_wheel->out_detail();
}
