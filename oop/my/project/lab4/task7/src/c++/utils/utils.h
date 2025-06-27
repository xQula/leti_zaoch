//
// Created by Юлий Максимов on 11.06.2024.
//

#ifndef GREATER_H
#define GREATER_H


namespace utils {
    class Utils {
    public:

        /**
         * Returns the greater of two values.
         *
         * @tparam T the type of the values being compared
         *
         * @param var1 the first value to compare
         * @param var2 the second value to compare
         *
         * @return the greater of var1 and var2
         *
         * @throws None
         */
        template <typename T>
        static auto greater(T var1, T var2) -> T;


        /**
         * Swaps the values of two variables.
         *
         * @tparam T the type of the variables
         *
         * @param var1 the first variable
         * @param var2 the second variable
         *
         * @return void
         *
         * @throws None
         */
        template <typename T>
        static auto swap(T &var1, T &var2) noexcept -> void;

        /**
         * Calculates the factorial of a given number using a for loop.
         *
         * @param n The number for which to calculate the factorial.
         * @param res The reference to the variable that will store the result.
         * @return True if the factorial calculation was successful, false otherwise.
         */
        template <typename T>
        static auto factorialFor(T n, T & res) -> bool;


        /**
         * Calculates the factorial of a given number using recursion.
         *
         * @tparam T the type of the number
         * @param n the number for which to calculate the factorial
         * @return the factorial of n
         */
        template <typename T>
        static auto factorualRecursive(T n) -> int;
    };

    template<typename T>
    auto Utils::greater(T var1, T var2) -> T {
        return var1 > var2 ? var1 : var2;
    }

    template<typename T>
    auto Utils::swap(T &var1, T &var2) noexcept -> void {
        std::swap(var1,var1);
    }

    template<typename T>
    auto Utils::factorialFor(T n, T &res) -> bool {
        for (int i = 1; i <= n; i++) {
            res = res * i;
        }
        return true;
    }

    template<typename T>
    auto Utils::factorualRecursive(T n) -> int {
        if (n==0) return 1;
        return n*factorualRecursive(n-1);
    }
}


#endif //GREATER_H
