//
// Created by Юлий Максимов on 11.06.2024.
//
#include "iostream"
#include "string"
#include "core.h"
#include "utils/utils.h"

namespace {
    /**
         * Reads an integer from the standard input and assigns it to the variable `var`.
         *
         * @param var reference to an integer variable where the input will be stored
         * @param str a string that will be printed to the standard output before reading the input
         *
         * @throws None
         */
    auto input(int &var, const std::string &str) -> void {
        std::cout << str;
        std::cin >> var;
    }

    /**
        * Outputs the given integer variable and string to the standard output.
        *
        * @param var the integer variable to be outputted
        * @param str the string to be outputted before the integer variable
        *
        * @return void
        *
        * @throws None
        */
    auto output(const int var, const std::string &str) -> void {
        std::cout << str << var << std::endl;
    }
}

/**
 * Processes the input value and calculates the factorial using both iterative and recursive methods.
 *
 * @return void
 *
 * @throws None
 */
auto root::Core::procces() -> void {
    int n, res = 1;
    input(n, "Enter n: ");
    if(utils::Utils::factorialFor(n, res)) {
        std::cout << "Successful" << std::endl;
    }else {
        std::cout << "FAIL" << std::endl;
    }
    output(res, "Res FOR: ");

    output(utils::Utils::factorualRecursive(n), "Res RECURSIVE: ");
}
