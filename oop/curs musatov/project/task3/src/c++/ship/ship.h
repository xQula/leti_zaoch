#pragma once
#include <memory>

namespace ship {
    struct Logbook {
        int m_daysRepair;
        int m_countDeysRepair;
        int m_capacity;
    };

    enum class TYPE_SHIP {
        LITTLE = 1,
        MEDIUM = 2,
        HIGH = 3
    };

    class Ship {
    public:
        Ship(int daysRepair, int capacity, TYPE_SHIP type, const std::string &name);
        ~Ship() = default;
        auto upCountDaysRepair() const -> void;
        auto resetCountDaysRepair() const -> void;
        [[nodiscard]] auto isFullRepair() const -> bool;
        [[nodiscard]] auto getCapacity() const -> int;
        [[nodiscard]] auto getType() const -> TYPE_SHIP;
        [[nodiscard]] auto getName() const -> std::string;
    private:
        std::shared_ptr<Logbook> m_logbook;
        TYPE_SHIP m_type;
        std::string m_name;
    };
}

