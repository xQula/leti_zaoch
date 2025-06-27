//
// Created by dokto on 10.06.2024.
//

#pragma once

#include "string"
#include "memory"

namespace nambers {
    struct Numbers {
        int i;
        int j;
        int k;
        std::string temp;
    };

    class DividingNumbers {
    public:
        DividingNumbers();
        void dividingNumbers() const;
    private:
        void addingNumerator() const;
        void addingDenominator() const;
        std::unique_ptr<Numbers> m_numbers;
    };
}
