//
// Created by Юлий Максимов on 11.06.2024.
//
#include "iostream"
#include "core.h"
#include "matrix/Matrix.h"

/**
 * Processes the core functionality of the root::Core class.
 *
 * This function prompts the user to enter two matrices, creates them using the math::Matrix class,
 * and then performs matrix multiplication between the two matrices. The result is printed to the console.
 *
 * @throws None
 */
auto root::Core::procces() -> void {
    std::cout << "First matrix: " << std::endl;
    math::Matrix matrix1;
    matrix1.createMatrix();
    matrix1.out();
    std::cout << "Second matrix: " << std::endl;
    math::Matrix matrix2;
    matrix2.createMatrix();
    matrix2.out();
    std::cout << "Result matrix: " << std::endl;
    math::Matrix matrix3 = matrix1 * matrix2;
    matrix1.out();
}
