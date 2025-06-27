//
// Created by dokto on 11.06.2024.
//

#include "CreateAccount.h"
#include "iostream"
#include "bank/AccountType.h"

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
    auto bankAccount = creatBankAccount();
    write(bankAccount);
    bankAccount.deposit(10);
    write( bankAccount);
    bankAccount.withdraw(50);
    write( bankAccount);
    std::cout << std::endl;
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
        (bankAccount.getType() == bank::AccountType::Checking ? "Checking" : "Deposit") << std::endl;
}

/**
 * Creates a new bank account by prompting the user for account number and balance,
 * and sets the account type to Checking.
 *
 * @return A new BankAccount object with the entered account number, balance, and type.
 *
 * @throws None
 */
auto bank::CreateAccount::creatBankAccount() -> bank::BankAccount {
    bank::BankAccount bankAccount;
    std::cout << "Enter the account balance! : ";
    double balance;
    std::cin >> balance;
    bankAccount.populate(balance);
    return bankAccount;
}
