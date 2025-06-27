#include <bank/createAccount.h>
#include <iostream>

/**
 * The main function that executes the bank account creation process.
 *
 * @return 0 indicating successful execution
 *
 * @throws std::logic_error if an error occurs during the account creation process
 */
int main()
{
    try {
        bank::CreateAccount::process();
    }catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
