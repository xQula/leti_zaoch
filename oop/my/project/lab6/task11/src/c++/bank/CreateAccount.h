//
// Created by dokto on 11.06.2024.
//

#pragma once
#include "bank/bankAccount.h"

namespace bank {
    class CreateAccount {
    public:
        static auto process() -> void;
    private:
        static auto write(const bank::BankAccount &bankAccount) -> void;
        static auto creatBankAccount() -> bank::BankAccount;
    };
}

