//
// Created by Юлий Максимов on 11.06.2024.
//

#pragma once

#include <string>
#include <utility>
#include <cord/ICord.h>

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
         * Checks if the value is a string.
         *
         * @tparam T the type of the value
         *
         * @param var the value to check
         *
         * @return true if the value is a string, false otherwise
         *
         * @throws None
         */
        template <typename T>
        static auto isToString(T var) -> bool;

        /**
         * Displays the coordinates of a given ICordinate object.
         *
         * @param cord Pointer to the ICordinate object to display.
         *
         * @return void
         *
         * @throws None
         */
        static auto display(const ICordinate *cord) -> void;
    };


    inline auto Utils::display(const ICordinate *cord) -> void {
        cord->Print();
    }


    template<typename T>
    auto Utils::greater(T var1, T var2) -> T {
        return var1 > var2 ? var1 : var2;
    }

    template<typename T>
   auto Utils::swap(T &var1, T &var2) noexcept -> void {
        std::swap(var1,var1);
    }

    template<typename T>
    auto Utils::isToString(T var) -> bool {
        if(std::is_same_v<T, std::string>) {
            return false;
        }
        if(std::is_same_v<T, int> ||
            std::is_same_v<T, double> ||
            std::is_same_v<T, bool> ||
            std::is_same_v<T, unsigned long>)
        {
            return true;
        }
        return false;
    }
}

