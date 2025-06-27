//
// Created by dokto on 10.06.2024.
//

#include <iostream>
#include "handlerString.h"

/**
 * Executes the input_name() and output_name() methods of the HandlerString class.
 *
 * @return void
 */
auto handler::HandlerString::operator()() -> void {
    input_name();
    output_name();
}

/**
 * Prompts the user to enter their name and stores it in the `m_name` member variable.
 *
 * @return void
 */
auto handler::HandlerString::input_name() -> void {
    std::cout << "Enter your name: ";
    std::cin >> m_name;
}

/**
 * Outputs the name stored in the `m_name` member variable to the console.
 *
 * @throws None
 */
auto handler::HandlerString::output_name() const -> void {
    std::cout << "Your name is: " << m_name << std::endl;
}
