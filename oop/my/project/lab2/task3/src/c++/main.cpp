#include "Core/bankState.h"

/**
 * The main function of the program.
 *
 * @return An integer indicating the exit status of the program.
 */
int main() {
    const bank::BankState state(bank::AccountType::Checking, bank::AccountType::Deposit);
    state.out();
    return 0;
}
