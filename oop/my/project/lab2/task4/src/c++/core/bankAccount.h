//
// Created by dokto on 10.06.2024.
//

#pragma once

#include <memory>

namespace bank {
    enum class AccountType{
        Checking,
        Deposit
    };
    struct BankAccount {
        long accNo;
        double accBal;
        AccountType accType;
    };
    class Core {
    public:
        Core();
        auto out () const -> void;
    private:
        std::unique_ptr<BankAccount> account;
    };
}


