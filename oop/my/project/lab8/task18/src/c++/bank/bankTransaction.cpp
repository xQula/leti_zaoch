//
// Created by Юлий Максимов on 13.06.2024.
//

#include "bankTransaction.h"

#include <ostream>
#include <fstream>
#include <iostream>

/**
 * Constructor for BankTransaction class.
 *
 * @param amount The amount for the transaction
 *
 */
bank::BankTransaction::BankTransaction(const double amount):
    m_amount(amount),
    m_dataTime("13 June"){
}

/**
 * Destructor for BankTransaction class.
 *
 * @param None
 *
 * @return None
 *
 * @throws std::logic_error if the file cannot be opened for writing
 */
bank::BankTransaction::~BankTransaction() {
    std::ofstream out;          // поток для записи
    out.open("../test.txt", std::ios_base::app);      // открываем файл для записи
    if (out.is_open())
    {
        std::cout << "File has been written" << std::endl << m_amount << " " << m_dataTime << std::endl;
        out << m_amount << std::endl;
        out << m_dataTime << std::endl;
    }else {
        throw std::logic_error("not open file");
    }
    out.close();
}


/**
 * Retrieves the amount associated with the BankTransaction object.
 *
 * @return The amount as a double.
 */
auto bank::BankTransaction::getAmount() const -> double {
    return m_amount;
}


/**
 * Retrieves the date and time associated with the BankTransaction object.
 *
 * @return The date and time as a string.
 */
auto bank::BankTransaction::getDataTime() const -> std::string {
    return m_dataTime;
}
