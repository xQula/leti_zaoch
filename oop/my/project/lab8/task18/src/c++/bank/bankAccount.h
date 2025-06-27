//
// Created by dokto on 11.06.2024.
//

#pragma once

#include "accountType.h"
#include "queue"
#include  "bank/bankTransaction.h"

namespace bank {
    class BankAccount {

    public:
        explicit BankAccount();
        explicit BankAccount(AccountType type, double balance);
        explicit BankAccount(AccountType type);
        explicit BankAccount(double balance);
        [[nodiscard]] auto getNumber() const -> long;
        [[nodiscard]] auto getBalance() const -> double;
        [[nodiscard]] auto getType() const -> AccountType;
        auto setNumber(long number) -> void;
        auto setBalance(double balance) -> void;
        auto setType(AccountType type) -> void;
        auto withdraw(double amount) -> bool;
        auto deposit(double amount) -> double;
        auto transferFrom(BankAccount &from, double amount) -> void;
        [[nodiscard]] auto getTranQueue() const -> const std::deque<BankTransaction>&;
        static auto reverse(std::string & str) -> void;
    private:
        long m_accNo;
        double m_accBal;
        AccountType m_accType;
        std::deque<BankTransaction> m_tranQueue;
    };
}

