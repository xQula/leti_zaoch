//
// Created by dokto on 11.06.2024.
//

#pragma once

#include <string>
#include <fstream>
#include <iostream>


class WorkFile {
public:
    auto readToFile() -> void;
    auto saveToFile() const -> void;
private:
    std::string fileData;
};

