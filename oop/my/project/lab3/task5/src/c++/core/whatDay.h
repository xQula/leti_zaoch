//
// Created by dokto on 10.06.2024.
//

#pragma once

#include <string>

namespace day{
    enum class MonthName
    {
        January = 31,
        February = 28,
        FebruaryLeap = 29,
        March = 31,
        April = 30,
        May = 31,
        June = 30,
        July = 31,
        August = 31,
        September = 30,
        October = 31,
        November = 31,
        December = 31
    };

    class WhatDay {
    public:
        void process();
    private:
        auto inputDay() -> void;
        auto inputYear() -> void;
        auto outputMonthDay() const -> void;
        auto checkDay(int & temp, MonthName month, const std::string &monthName) -> bool;
        auto calculateMonthDay() -> void;
        int m_day{};
        int year{};
        std::string m_monthDay{};
        bool m_isLeapYear{false};
    };
}


