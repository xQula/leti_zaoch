#include <iostream>
#include "utils/utils.h"
#include "cord/Cordinate.h"
#include "memory"

/**
 * The main function of the C++ program.
 *
 * @return 0 indicating successful execution.
 *
 * @throws None.
 */
int main()
{
    const std::unique_ptr<ICordinate> cord = std::make_unique<Cordinate>(21.0,68.0);
    utils::Utils::display(cord.get());
   return 0;
}
