//
// Created by Юлий Максимов on 11.06.2024.
//
#include "iostream"
#include "core.h"
#include "read/ReadFile.h"
#include "sort/SortStr.h"

namespace {
    /**
     * Prints the given variable with the given string prefix.
     *
     * @param var The variable to be printed.
     * @param str The string prefix to be printed before the variable.
     *
     * @return void
     *
     * @throws None
     */
    template <typename T>
    auto out(T var, const std::string &str) {
        std::cout << str << var << std::endl;
    }
}

/**
 * Processes the input file and prints the count of symbols, lines, consonants, and vowels.
 *
 * @return void
 *
 * @throws None
 */
auto root::Core::procces() -> void {
    const auto [
        countSymbol,
        countLines,
        countVowels,
        countConsonants]
            = str::SortStr::sort(str::ReadFile::read());
    out(countSymbol, "Count symbol: ");
    out(countLines, "Count lines: ");
    out(countConsonants, "Count consonants: ");
    out(countVowels, "Count vowels: ");
}
