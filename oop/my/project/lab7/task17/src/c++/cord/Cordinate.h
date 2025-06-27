//
// Created by dokto on 11.06.2024.
//

#pragma once
#include <iostream>
#include <cord/ICord.h>


class Cordinate final : public ICordinate{

public:
    /**
     * Constructs a Cordinate object with the default coordinates (0.0, 0.0).
     *
     * @throws None
     */
    Cordinate() {
        x=0.0;
        y=0.0;
    }

    /**
     * Constructs a Cordinate object with the given coordinates.
     *
     * @param px the x-coordinate
     * @param py the y-coordinate
     */
    Cordinate(const double px, const double py) {
        x=px;
        y=py;
    }

    /**
     * Prints the x and y coordinates of the Cordinate object to the standard output.
     *
     * @throws None
     */
    void Print() const override {
        std::cout << x << " " << y << std::endl;
    }
private:
    double x{};
    double y{};
};


