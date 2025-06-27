//
// Created by dokto on 11.06.2024.
//

#include "bankAccount.h"

/**
 * Populates the bank account with the given account number and balance.
 *
 * @param number The account number.
 * @param balance The account balance.
 *
 * @throws None.
 */
void bank::BankAccount::populate(const int number, const double balance) {
    accNo = number;
    accBal = balance;
    accType = AccountType::Checking;
}


/**
 * Returns the account number.
 *
 * @return The account number.
 *
 * @throws None.
 */
auto bank::BankAccount::getNumber() const -> long {
    return accNo;
}


/**
 * Returns the account balance.
 *
 * @return The account balance.
 *
 * @throws None.
 */
auto bank::BankAccount::getBalance() const -> double {
    return accBal;
}


/**
 * Returns the account type.
 *
 * @return The account type.
 *
 * @throws None.
 */
auto bank::BankAccount::getType() const -> AccountType {
    return accType;
}


/**
 * Sets the account number.
 *
 * @param number The account number.
 *
 * @throws None.
 */
auto bank::BankAccount::setNumber(const long number) -> void {
    accNo = number;
}

/**
 * Sets the balance of the bank account.
 *
 * @param balance The new balance to be set.
 *
 * @return void
 *
 * @throws None
 */
auto bank::BankAccount::setBalance(const double balance) -> void {
    accBal = balance;
}


/**
 * Sets the account type.
 *
 * @param type The new account type.
 *
 * @return void
 *
 * @throws None
 */
auto bank::BankAccount::setType(const AccountType type) -> void {
    accType = type;
}
