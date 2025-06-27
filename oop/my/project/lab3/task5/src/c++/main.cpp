#include "core/whatDay.h"
#include <iostream>

/**
 * The main function of the C++ program.
 *
 * @return The exit status of the program.
 *
 * @throws std::logic_error if an error occurs during the execution of the program.
 */
int main()
{
    try {
        day::WhatDay whatDay;
        whatDay.process();
    }catch (const std::logic_error &e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
