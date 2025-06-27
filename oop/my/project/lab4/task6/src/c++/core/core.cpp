//
// Created by Юлий Максимов on 11.06.2024.
//
#include "iostream"
#include "string"
#include "core.h"
#include "utils/utils.h"

namespace {
    /**
     * Reads an integer value from the user input and assigns it to the given variable.
     *
     * @param var a reference to an integer variable to store the input value
     * @param str a constant reference to a string representing the prompt message
     *
     * @return void
     *
     * @throws None
     */
    auto input(int &var, const std::string &str) -> void {
        std::cout << str;
        std::cin >> var;
    }

    /**
         * Outputs the given integer variable and string to the console.
         *
         * @param var the integer variable to output
         * @param str the string to output before the integer variable
         *
         * @return void
         */
    auto output(const int var, const std::string &str) -> void {
        std::cout << str << var << std::endl;
    }
}

/**
 * Processes two integers by prompting the user to enter them,
 * finding the greater number, and swapping the two.
 *
 * @return void
 *
 * @throws None
 */
auto root::Core::procces() -> void {
    int x, y;
    input(x, "Enter first number: ");
    input(y, "Enter second number: ");
    const int greater = utils::Utils::greater<int>(x, y);
    output(greater, "Greater number: ");
    output(x, "First number: ");
    output(y, "Second number: ");
    std::cout << "SWAP" << std::endl;
    utils::Utils::swap<int>(x, y);
    output(x, "First number: ");
    output(y, "Second number: ");

}
