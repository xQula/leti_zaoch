#include <stdexcept>
#include <iostream>
#include "core/core.h"

/**
 * The main function of the C++ program.
 *
 * @param argc the number of command line arguments
 * @param argv an array of command line arguments
 *
 * @return an integer representing the exit status of the program
 *
 * @throws None
 */
int main(int argc, char *argv[]) {
    root::Core::procces();
    return 0;
}
