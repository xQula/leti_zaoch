//
// Created by dokto on 10.06.2024.
//

#pragma once
namespace bank {
    enum class AccountType{
        Checking,
        Deposit
    };
    class BankState {
    public:
        BankState(const AccountType &goldAccount, const AccountType &platinumAccount);
        void out() const;
    private:
        AccountType goldAccount;
        AccountType platinumAccount;
    };
}


