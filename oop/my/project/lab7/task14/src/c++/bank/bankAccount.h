//
// Created by dokto on 11.06.2024.
//

#pragma once

#include "AccountType.h"
#include "string"

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
        auto withdraw(double amount) -> bool;
        auto deposit(double amount) -> double;
        auto transferFrom(BankAccount &from, double amount) -> void;

        static void reverse(std::string & str);
    private:
        auto NextNumber() -> long;
        long accNo = 0;
        double accBal = 0;
        AccountType accType = AccountType::Checking;
        long nextNumber = 123;
    };
}

