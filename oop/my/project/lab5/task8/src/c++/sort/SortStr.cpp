//
// Created by Юлий Максимов on 11.06.2024.
//

#include "SortStr.h"

/**
* Sorts a given string and returns a CountFile object containing the count of symbols, lines, vowels, and consonants.
*
* @param str The string to be sorted.
*
* @return A CountFile object containing the count of symbols, lines, vowels, and consonants.
*
* @throws None
*/
auto str::SortStr::sort(const std::string &str) -> CountFile {
    CountFile tmp(0,0,0,0);
    tmp.countSymbol = static_cast<int>(str.size());
    for(const auto &i: str) {
        if(const auto x = std::tolower(i);
            x == 'e' || x == 'y' || x == 'u' || x == 'i' || x == 'o' || x == 'a')
        {
            tmp.countVowels++;
        }else if (i == '\n'){
            tmp.countLines++;
        }else {
            tmp.countConsonants++;
        }
    }
    return tmp;
}
