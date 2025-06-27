//
// Created by dokto on 11.06.2024.
//

#include "createAccount.h"
#include "iostream"
#include "bank/accountType.h"



/**
 * Processes the creation of bank accounts, performs various operations like deposit, withdrawal, and transfers.
 *
 * @return None
 *
 * @throws None
 */
auto bank::CreateAccount::process() -> void {
    auto bankAccount1 = BankAccount(bank::AccountType::Checking, 100);
    auto bankAccount2 = BankAccount(100);
    auto bankAccount3 = BankAccount(bank::AccountType::Deposit);
    auto bankAccount4 = BankAccount();
    bankAccount1.deposit(10);
    bankAccount2.withdraw(20);
    bankAccount3.transferFrom(bankAccount4,30);
    write(bankAccount1);
    write(bankAccount2);
    write(bankAccount3);
    write(bankAccount4);
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
    std::cout << "Transaction history: " << std::endl;
    for (const auto &tran : bankAccount.getTranQueue()) {
        std::cout << tran.getAmount() << std::endl;
        std::cout << tran.getDataTime();
    }
    std::cout << std::endl << std::endl;
}

