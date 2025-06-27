//
// Created by dokto on 10.06.2024.
//

#include "bankAccount.h"
#include <iostream>

namespace {

    /**
   * Outputs the corresponding account type to the console.
   *
   * @param type The account type to be outputted.
   *
   * @return void
   *
   * @throws None
   */
    auto out(const bank::AccountType type) -> void {
        if(type == bank::AccountType::Checking) {
            std::cout << "Checking" << std::endl;
        } else if(type == bank::AccountType::Deposit) {
            std::cout << "Deposit" << std::endl;
        }
    }
}

/**
 * Constructor for the Core class. Initializes the account member variable with a unique pointer to a BankAccount object.
 *
 * @throws None
 */
bank::Core::Core():
account(std::make_unique<BankAccount>(1, 22, bank::AccountType::Checking))
{

}

/**
 * Outputs the account number, balance, and account type of the bank account associated with the Core object.
 *
 * @throws None
 */
auto bank::Core::out() const -> void {
    std::cout << account->accNo << std::endl;
    std::cout << account->accBal << std::endl;
    ::out(account->accType);
}
