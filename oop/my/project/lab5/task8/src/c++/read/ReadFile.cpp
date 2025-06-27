//
// Created by Юлий Максимов on 11.06.2024.
//

#include "ReadFile.h"
#include <fstream>

/**
 * Reads the contents of a file and returns it as a string.
 *
 * @return The contents of the file as a string.
 *
 * @throws std::logic_error If the file cannot be opened.
 */
auto str::ReadFile::read() -> std::string {
    std::string line;

    std::ifstream in("../test.txt");
    if (in.is_open())
    {
        while (!in.eof())
        {
            std::string tmp;
            std::getline(in, tmp);
            line += tmp;
            line += '\n';
        }
    }else {
        throw std::logic_error("Not find file");
    }
    in.close();
    return  line;
}
