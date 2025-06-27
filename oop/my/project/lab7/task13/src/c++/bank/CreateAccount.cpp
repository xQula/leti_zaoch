//
// Created by dokto on 11.06.2024.
//

#include "CreateAccount.h"
#include "iostream"
#include "bank/AccountType.h"


namespace {
    /**
    * Creates a bank account with the given account number and a default balance of 100.
    *
    * @param num The account number.
    *
    * @return A bank::BankAccount object representing the newly created account.
    *
    * @throws None.
    */
    auto createBankAccount(const int num) -> bank::BankAccount {
        bank::BankAccount tmp ;
        tmp.populate( num, 100);
        return tmp;
    }
}
/**
 * Executes the process of creating a bank account.
 *
 * This function creates a new bank account by calling the `creatBankAccount` function
 * and stores the result in the `bankAccount` variable. Then, it calls the `write`
 * function to display the details of the bank account.
 *
 * @return void
 */
auto bank::CreateAccount::process() -> void {
    auto bankAccount1 = createBankAccount(1);
    write(bankAccount1);
    auto bankAccount2 = createBankAccount(2);
    write(bankAccount2);
    std::cout << "Transfer" << std::endl << std::endl;
    bankAccount1.transferFrom( bankAccount2, 10);
    write(bankAccount1);
    write(bankAccount2);
}

/**
 * Writes the details of a bank account to the standard output.
 *
 * @param bankAccount the bank account to write
 *
 * @return void
 *
 * @throws None
 */
auto bank::CreateAccount::write(const bank::BankAccount &bankAccount) -> void {
    std::cout << "Account number is " << bankAccount.getNumber() << std::endl;
    std::cout << "Account balance is " << bankAccount.getBalance() << std::endl;
    std::cout << "Account type is " <<
        (bankAccount.getType() == bank::AccountType::Checking ? "Checking" : "Deposit") << std::endl << std::endl;
}

