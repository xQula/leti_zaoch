//
// Created by Юлий Максимов on 11.06.2024.
//

#pragma once
#include "string"

namespace str {
    struct CountFile{
        /**
        * Constructs a CountFile object with the given values.
        *
        * @param i the number of consonants
        * @param x the number of lines
        * @param f the number of symbols
        * @param g the number of vowels
        */
        CountFile(const int i, const int x, const int f, const int g) {
            countConsonants = i;
            countLines = x;
            countSymbol = f;
            countVowels = g;
        }
        int countSymbol;
        int countLines;
        int countVowels;
        int countConsonants;
    };
    class SortStr {
    public:
        static auto sort(const std::string& str) -> CountFile;
    };
}

