//
// Created by dokto on 11.06.2024.
//

#pragma once
#include "AccountType.h"
namespace bank {
    class BankAccount {

    public:
        void populate(int number, double balance);
        [[nodiscard]] auto getNumber() const -> long;
        [[nodiscard]] auto getBalance() const -> double;
        [[nodiscard]] auto getType() const -> AccountType;
        auto setNumber(long number) -> void;
        auto setBalance(double balance) -> void;
        auto setType(AccountType type) -> void;
    private:
        long accNo = 0;
        double accBal = 0;
        AccountType accType = AccountType::Checking;
    };
}

