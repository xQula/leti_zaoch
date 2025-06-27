#include <stdexcept>
#include <iostream>
#include "core/core.h"

/**
 * The main function of the program.
 *
 * @param argc the number of command line arguments
 * @param argv an array of command line arguments
 *
 * @return an integer representing the exit status of the program
 *
 * @throws std::logic_error if an error occurs during the execution of the program
 */
int main(int argc, char *argv[]) {
    try {
        root::Core::procces();
    }catch (std::logic_error &e) {
        std:: cout << e.what() << std::endl;
    }
    return 0;
}
