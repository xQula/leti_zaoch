//
// Created by dokto on 10.06.2024.
//

#include <iostream>
#include "WhatDay.h"

namespace {
    constexpr auto MIN_DAY = 1;
    auto MAX_DAY = 365;
}

/**
 * Executes the main process of the WhatDay class by calling the inputYear, inputDay, calculateMonthDay, and outputMonthDay functions in sequence.
 *
 * @throws None
 */
auto day::WhatDay::process() -> void {
    this->inputYear();
    this->inputDay();
    this->calculateMonthDay();
    this->outputMonthDay();
}

/**
 * Reads a day from the user input and checks if it is within the valid range.
 *
 * @throws std::logic_error if the day is outside the valid range
 */
auto day::WhatDay::inputDay() -> void {
    std::cout << "Enter day: ";
    std::cin >> m_day;
    if(m_day < MIN_DAY || m_day > MAX_DAY) {
        throw std::logic_error( "Wrong day!" );
    }
}

/**
      * Prompts the user to enter a year and checks if it is a leap year.
      * If the year is not a leap year, sets `m_isLeapYear` to false.
      * If the year is a leap year, sets `m_isLeapYear` to true and updates `MAX_DAY` to 366.
      *
      * @throws None
      */
auto day::WhatDay::inputYear() -> void {
    std::cout << "Enter year: ";
    std::cin >> year;

    if(year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) {
        m_isLeapYear = false;
    } else {
        m_isLeapYear = true;
    }
    if(m_isLeapYear) {
        MAX_DAY = 366;
    }
}

/**
 * Outputs the month and day to the console.
 *
 * @throws None
 */
auto day::WhatDay::outputMonthDay() const -> void {
    std::cout << m_monthDay << std::endl;
}

/**
       * Checks if the given day is greater than the month and updates the day accordingly.
       * If the day is greater than the month, it subtracts the month from the day and returns false.
       * Otherwise, it constructs the month and day string and returns true.
       *
       * @param temp the day to be checked
       * @param month the maximum day of the month
       * @param monthName the name of the month
       *
       * @return true if the day is less than or equal to the month, false otherwise
       *
       * @throws None
       */
auto day::WhatDay::checkDay(int & temp, MonthName month,const std::string &monthName) -> bool {

    if(temp > static_cast<int>(month)) {
        temp -= static_cast<int>(month);
        return false;
    }
    m_monthDay = monthName + " " + std::to_string(temp);
    return true;
}


/**
 * Calculates the month and day based on the given day of the year.
 *
 * @return void
 *
 * @throws None
 */
auto day::WhatDay::calculateMonthDay() -> void {
    int temp = m_day;
    if(checkDay(temp, MonthName::January, "January")) return;
    if(m_isLeapYear) {
        if(checkDay(temp, MonthName::FebruaryLeap, "February")) return;
    }else {
        if(checkDay(temp, MonthName::February, "February")) return;
    }
    if(checkDay(temp, MonthName::March, "March")) return;
    if(checkDay(temp, MonthName::April, "April")) return;
    if(checkDay(temp, MonthName::May, "May")) return;
    if(checkDay(temp, MonthName::June, "June")) return;
    if(checkDay(temp, MonthName::July, "July")) return;
    if(checkDay(temp, MonthName::August, "August")) return;
    if(checkDay(temp, MonthName::September, "September")) return;
    if(checkDay(temp, MonthName::October, "October")) return;
    if(checkDay(temp, MonthName::November, "November")) return;
    checkDay(temp, MonthName::December, "December");
}
