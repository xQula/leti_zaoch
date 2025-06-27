//
// Created by dokto on 11.06.2024.
//

#include "WorkFile.h"

auto WorkFile::readToFile() -> void {
    std::string fileName;
    std::cout << "Enter file name read: ";
    std::cin >> fileName;
    if (std::ifstream myfile(fileName); myfile.is_open()) {
        std::string line;
        while (getline(myfile, line)) {
            fileData += line;
        }
        myfile.close();
    }else {
        throw std::runtime_error("File not found");
    }
}

auto WorkFile::saveToFile() const -> void {
    std::string fileName;
    std::cout << "Enter file name write: ";
    std::cin >> fileName;
    std::ofstream myfile(fileName);
    if(!myfile.is_open()){throw std::runtime_error("File not found");}
    std::string tmp;
    for(const auto &i: fileData) {
        tmp += static_cast<char>(toupper(i));
    }
    myfile << tmp;
    myfile.close();
}
