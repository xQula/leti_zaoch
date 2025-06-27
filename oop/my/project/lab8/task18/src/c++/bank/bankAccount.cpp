//
// Created by dokto on 11.06.2024.
//

#include "bankAccount.h"
#include "algorithm"


namespace {
    long nextNumber = 123;

    /**
 * Increments and returns the next number in the sequence.
 *
 * @return The next number in the sequence.
 */
    auto NextNumber() -> long {
        return ++nextNumber;
    }
}
/**
 * Constructs a BankAccount object with default values.
 *
 * This constructor initializes the account number, balance, and type with default values.
 * The account number is generated using the `nextNumber()` function. The balance is set to 0.
 * The account type is set to `AccountType::Checking`.
 *
 * @return None.
 *
 * @throws None.
 */
bank::BankAccount::BankAccount():
    m_accNo(::NextNumber()),
    m_accBal(0),
    m_accType(AccountType::Checking)
{
}

/**
 * Constructs a BankAccount object with the given account type and initializes the account number,
 * balance, and type.
 *
 * @param type The account type of the BankAccount object.
 *
 * @return None.
 *
 * @throws None.
 */
bank::BankAccount::BankAccount(const AccountType type, const double balance):
    m_accNo(::NextNumber()),
    m_accBal(balance),
    m_accType(type)
{
}

bank::BankAccount::BankAccount(const AccountType type):
    m_accNo(::NextNumber()),
    m_accBal(0),
    m_accType(type)
{
}

/**
 * Constructs a BankAccount object with the given balance and sets the account number, balance, and type.
 *
 * @param balance The initial balance of the account.
 *
 * @throws None
 */
bank::BankAccount::BankAccount(const double balance):
    m_accNo(::NextNumber()),
    m_accBal(balance),
    m_accType(AccountType::Checking)
{
}

/**
 * Returns the account number.
 *
 * @return The account number.
 *
 * @throws None.
 */
auto bank::BankAccount::getNumber() const -> long {
    return m_accNo;
}


/**
 * Returns the account balance.
 *
 * @return The account balance.
 *
 * @throws None.
 */
auto bank::BankAccount::getBalance() const -> double {
    return m_accBal;
}


/**
 * Returns the account type.
 *
 * @return The account type.
 *
 * @throws None.
 */
auto bank::BankAccount::getType() const -> AccountType {
    return m_accType;
}


/**
 * Sets the account number.
 *
 * @param number The account number.
 *
 * @throws None.
 */
auto bank::BankAccount::setNumber(const long number) -> void {
    m_accNo = number;
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
    m_accBal = balance;
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
    m_accType = type;
}

/**
 * Withdraws the specified amount from the bank account if there are sufficient funds.
 *
 * @param amount The amount to be withdrawn.
 *
 * @return True if the withdrawal was successful, false otherwise.
 *
 * @throws None
 */
auto bank::BankAccount::withdraw(const double amount) -> bool {
    const auto sufficientFunds = m_accBal >= amount;
    if (sufficientFunds) {
        m_tranQueue.emplace_back(amount);
        m_accBal -= amount;
    }
    return sufficientFunds ;
}

/**
 * Deposits the specified amount into the bank account.
 *
 * @param amount The amount to be deposited.
 *
 * @return The updated balance of the bank account after the deposit.
 *
 * @throws None
 */
auto bank::BankAccount::deposit(const double amount) -> double {
    m_tranQueue.emplace_back(amount);
    return  m_accBal += amount;
}

/**
 * Transfers the specified amount from the given BankAccount to the current BankAccount.
 *
 * @param from The BankAccount to transfer the amount from.
 * @param amount The amount to be transferred.
 *
 * @return void
 *
 * @throws None
 */
auto bank::BankAccount::transferFrom(BankAccount &from, const double amount) -> void {
    if(from.withdraw(amount)) {
        this->deposit(amount);
    }
}

auto bank::BankAccount::getTranQueue() const -> const std::deque<BankTransaction>& {
    return m_tranQueue;
}

/**
 * Reverses the given string in-place.
 *
 * @param str The string to be reversed.
 *
 * @throws None
 */
void bank::BankAccount::reverse(std::string &str) {
    std::ranges::reverse(str);
}

