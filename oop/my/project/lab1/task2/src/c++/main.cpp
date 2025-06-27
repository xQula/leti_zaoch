#include "Core/dividingNumbers.h"
#include "iostream"

/**
 * The main function of the program.
 *
 * This function initializes a `DividingNumbers` object and calls its `dividingNumbers` method.
 * If an exception of type `logic_error` is thrown during the execution of `dividingNumbers`,
 * the error message is printed to the standard output.
 *
 * @return EXIT_SUCCESS if the program executes successfully.
 */
int main()
{
    try {
        const nambers::DividingNumbers dividingNumbers;
        dividingNumbers.dividingNumbers();
    }catch (std::logic_error &error) {
        std::cout << error.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
