//
// Created by dokto on 10.06.2024.
//
#include "iostream"
#include "bankState.h"

namespace {
/**
 * Outputs the gold and platinum accounts held by the bank state.
 *
 * @return void
 *
 * @throws None
 */
    auto out(const bank::AccountType &state) -> void {
        if(state == bank::AccountType::Checking) {
            std::cout << "Checking" << std::endl;
        } else if(state == bank::AccountType::Deposit) {
            std::cout << "Deposit" << std::endl;
        }
    }
}

/**
 * Constructs a BankState object with the given gold and platinum accounts.
 *
 * @param goldAccount the gold account
 * @param platinumAccount the platinum account
 */
bank::BankState::BankState(const AccountType &goldAccount, const AccountType &platinumAccount)
        : goldAccount(goldAccount), platinumAccount(platinumAccount)
{

}

/**
 * The main function initializes a `BankState` object with two `AccountType`s:
 * `Checking` and `Deposit`. It then calls the `out()` function of the `BankState`
 * object to print the state of the bank. The function returns 0 indicating a
 * successful execution.
 *
 * @return 0 indicating successful execution
 *
 * @throws None
 */
void bank::BankState::out() const {
    ::out(goldAccount);
    ::out(platinumAccount);
}
