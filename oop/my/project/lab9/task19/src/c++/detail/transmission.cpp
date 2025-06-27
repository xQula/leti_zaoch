//
// Created by xqula on 21.06.24.
//

#include "transmission.h"
#include "iostream"

detail::Transmission::Transmission(std::string made,
                                   std::string name,
                                   const int numberGears,
                                   const detail::TYPE_OF_TRANSMISSION typeOfTransmission)
    : Detail(std::move(made), std::move(name)),
    m_numberGears(numberGears),
    m_typeOfTransmission(typeOfTransmission)
{
}

auto detail::Transmission::out_detail() -> void {
    std::cout << "**********************" << std::endl;
    Detail::out_detail();
    std::cout << "Number of gears: " << m_numberGears << std::endl;
    std::cout << "Type of transmission: ";
    switch (static_cast<int>(m_typeOfTransmission)) {
        case 0:
            std::cout << "MANUAL" << std::endl;
            break;
        case 1:
            std::cout << "AUTOMATIC" << std::endl;
            break;
        case 2:
            std::cout << "VARIATION" << std::endl;
            break;
        case 3:
            std::cout << "ROBOT" << std::endl;
            break;
    }
    std::cout << "**********************" << std::endl;
}
