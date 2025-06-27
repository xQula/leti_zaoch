//
// Created by xqula on 21.06.24.
//

#include "sportcar.h"
#include "iostream"

car::SportCar::SportCar(std::string made,
                        std::string name,
                        std::unique_ptr<detail::Detail> body,
                        std::unique_ptr<detail::Detail> engine,
                        std::unique_ptr<detail::Detail> transmission,
                        std::unique_ptr<detail::Detail> wheel,
                        bool isNitro):
    Car(std::move(made), std::move(name), std::move(body), std::move(engine), std::move(transmission), std::move(wheel)),
    m_isNitro(isNitro)
{

}

auto car::SportCar::out_car() -> void {
    std::cout << "-----------------------" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Sport car:" << std::endl;
    Car::out_car();
    std::cout << "There is nitro: ";
    if(m_isNitro){
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
    std::cout << "-----------------------" << std::endl;
}
