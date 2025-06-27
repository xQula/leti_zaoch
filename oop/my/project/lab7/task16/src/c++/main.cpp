#include <iostream>
#include "utils/utils.h"

/**
 * The main function of the C++ program.
 *
 * @return an integer representing the exit status of the program
 *
 * @throws None
 */
int main()
{
   constexpr int x = 1;
   constexpr unsigned long y = 2;
   const std::string z = "3";
   std::cout << "int is toString: " << (utils::Utils::isToString(x) ? "true" : "false") << std::endl;
   std::cout << "unsigned long is toString: " << (utils::Utils::isToString(y) ? "true" : "false") << std::endl;
   std::cout << "string is toString: " << (utils::Utils::isToString(z) ? "true" : "false") << std::endl;
}
