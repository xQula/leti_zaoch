//
// Created by xqula on 21.06.24.
//

#include "body.h"
#include "iostream"

detail::Body::Body(std::string made, std::string name, std::string color, detail::TYPE_MATERIAL typeMaterial)
    : Detail(std::move(made), std::move(name)),
    m_color(std::move(color)),
    m_typeMaterial(typeMaterial)
{
}

auto detail::Body::out_detail() -> void {
    std::cout << "**********************" << std::endl;
    Detail::out_detail();
    std::cout << "Color: " << m_color << std::endl;
    std::cout << "Type material: ";
    switch (static_cast<int>(m_typeMaterial)) {
        case 0:
            std::cout << "METAL" << std::endl;
            break;
        case 1:
            std::cout << "ALUMINUM" << std::endl;
            break;
        case 2:
            std::cout << "CARBON" << std::endl;
            break;
    }
    std::cout << "**********************" << std::endl;
}
