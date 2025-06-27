#include <iostream>
#include "core/Core.h"


int main() {
    try {
        core::Core core;
        core.process();
    }catch (const std::runtime_error &e){
        std::cerr << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
