//
// Created by dokto on 10.06.2024.
//

#include <iostream>
#include "dividingNumbers.h"

/**
 * Constructor for the DividingNumbers class.
 *
 * Initializes the m_numbers member variable with a unique pointer to a Numbers object.
 *
 * @return None.
 */
nambers::DividingNumbers::DividingNumbers():
    m_numbers(std::make_unique<Numbers>())
{
}

/**
 * Divides the numerator by the denominator and prints the result.
 *
 * @throws std::logic_error if the denominator is zero.
 */
void nambers::DividingNumbers::dividingNumbers() const {
    addingNumerator();
    addingDenominator();
    m_numbers->k = m_numbers->i / m_numbers->j;
    std::cout << "the result is: " << m_numbers->k << std::endl;
}

/**
 * Prompts the user to enter a numerator number and stores it in the `m_numbers` object.
 *
 * @throws None
 */
void nambers::DividingNumbers::addingNumerator() const {
    std::cout << "enter the a Numerator number:";
    std::cin >> m_numbers->temp;
    m_numbers->i = std::stoi(m_numbers->temp);
}

/**
 * Prompts the user to enter a denominator number and stores it in the `m_numbers` object.
 *
 * @throws std::logic_error if the denominator is zero.
 */
void nambers::DividingNumbers::addingDenominator() const {
    std::cout << "enter the a denominator number:";
    std::cin >> m_numbers->temp;
    if(m_numbers->temp == "0") {
        throw std::logic_error("denominator can't be zero");
    }
    m_numbers->j = std::stoi(m_numbers->temp);
}
