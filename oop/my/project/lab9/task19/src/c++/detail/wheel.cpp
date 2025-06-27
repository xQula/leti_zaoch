//
// Created by xqula on 21.06.24.
//

#include "wheel.h"

#include <utility>
#include "iostream"

detail::Wheel::Wheel(
        std::string made,
        std::string name,
        const int diameterDisc,
        const int loadIndex,
        const detail::SPEED_INDEX speedIndex) :
    m_diameterDisc(diameterDisc),
    m_loadIndex(loadIndex),
    m_speedIndex(speedIndex),
    Detail(std::move(made),std::move(name))
{

}

/*
 * Outputs the details of a car to the console.
 *
 * @param car The car to output the details of.
 */
auto detail::Wheel::out_detail() -> void {
    std::cout << "**********************" << std::endl;
    Detail::out_detail();
    std::cout << "Diameter disc: " << m_diameterDisc << std::endl;
    std::cout << "Load index: " << m_loadIndex << std::endl;
    std::cout << "Speed index: " << static_cast<int>(m_speedIndex) << std::endl;
    std::cout << "**********************" << std::endl;
}
