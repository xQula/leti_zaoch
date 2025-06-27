//
// Created by xqula on 21.06.24.
//

#include "detail.h"
#include "string"

namespace detail {
    enum class TYPE_MATERIAL {
        METAL = 0,
        ALUMINUM = 1,
        CARBON = 2
    };
    class Body: public Detail {
    public:
        explicit Body(std::string made, std::string name, std::string color, TYPE_MATERIAL typeMaterial);
        auto out_detail() -> void override;
    private:
        std::string m_color;
        TYPE_MATERIAL m_typeMaterial;
    };
}
