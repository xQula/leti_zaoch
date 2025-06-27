//
// Created by xqula on 21.06.24.
//

#include "racingcar.h"
#include "iostream"

car::RacingCar::RacingCar(std::string made,
                          std::string name,
                          std::unique_ptr<detail::Detail> body,
                          std::unique_ptr<detail::Detail> engine,
                          std::unique_ptr<detail::Detail> transmission,
                          std::unique_ptr<detail::Detail> wheel,
                          car::TYPE_RACING typeRacing):
    Car(std::move(made), std::move(name), std::move(body), std::move(engine), std::move(transmission), std::move(wheel)),
    m_typeRacing(typeRacing)
{

}

auto car::RacingCar::out_car() -> void {
    std::cout << "-----------------------" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Racing car:" << std::endl;
    Car::out_car();
    std::cout << "type of racing car: ";
    switch (static_cast<int>(m_typeRacing)) {
        case 0:
            std::cout << "F1" << std::endl;
            break;
        case 1:
            std::cout << "drift" << std::endl;
            break;
        case 2:
            std::cout << "rally" << std::endl;
            break;
        default:
            std::cout << "unknown" << std::endl;
            break;
    }
    std::cout << "-----------------------" << std::endl;
    std::cout << "-----------------------" << std::endl;
}
