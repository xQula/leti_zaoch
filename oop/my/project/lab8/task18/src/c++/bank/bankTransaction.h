//
// Created by Юлий Максимов on 13.06.2024.
//
#pragma once
#include <string>

namespace bank {
    class BankTransaction {
    public:
        explicit BankTransaction(double amount);
        virtual ~BankTransaction();
        [[nodiscard]] auto getAmount() const -> double;
        [[nodiscard]] auto getDataTime() const -> std::string;
    private:
        double m_amount;
        std::string m_dataTime;
    };
}