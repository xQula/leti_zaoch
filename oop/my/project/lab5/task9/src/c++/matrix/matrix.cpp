//
// Created by dokto on 11.06.2024.
//

#include "matrix.h"
#include <iostream>

using VectorInt = std::vector<int>;
using MatrixInt = std::vector<VectorInt>;

namespace {
    /**
     * Reads an integer from the user input.
     *
     * @return The integer entered by the user.
     *
     * @throws None
     */
    auto inputNum() -> int {
        int var;
        std::cout << "Enter number: ";
        std::cin >> var;
        return var;
    }

    /**
     * Generates a vector of integers by calling the `inputNum()` function twice.
     *
     * @return A vector of integers containing the values returned by `inputNum()`.
     */
    auto inputVec() -> VectorInt {
        return {inputNum(), inputNum()};
    }

    /**
     * Generates a matrix of integers by calling the `inputVec()` function twice.
     *
     * @return A matrix of integers containing the values returned by `inputVec()`.
     */
    auto createMatrix() -> MatrixInt {
        return {{inputVec()}, {inputVec()}};
    }
}

/**
 * Default constructor for the math::Matrix class.
 *
 * This constructor initializes a math::Matrix object with default values.
 *
 * @return void
 */
math::Matrix::Matrix() = default;

/**
 * Initializes the matrix of the math::Matrix object by calling the ::createMatrix() function.
 *
 * @throws None
 */
void math::Matrix::createMatrix() {
    matrix = ::createMatrix();
}

/**
 * Outputs the matrix to the console.
 *
 * This function iterates over the rows and columns of the matrix and prints
 * each element to the console. After printing each row, a new line is
 * printed. Finally, a new line is printed after printing the entire matrix.
 *
 * @return void
 *
 * @throws None
 */
auto math::Matrix::out() -> void {
    std::cout << "Matrix: " << std::endl;
    for(const auto& i: matrix) {
        for(const auto &k: i) {
            std::cout << k << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Multiplies two matrices together.
 *
 * This function multiplies matrix `a` by matrix `b` and returns the result as a new matrix `res`.
 * The resulting matrix `res` has the same number of rows as matrix `a` and the same number of columns as matrix `b`.
 * The elements of the resulting matrix `res` are computed by summing the products of the corresponding elements of matrix `a` and matrix `b`.
 *
 * @param a The first matrix to be multiplied.
 * @param b The second matrix to be multiplied.
 * @return The resulting matrix after the multiplication.
 *
 * @throws None.
 */
math::Matrix math::operator*(const Matrix &a, const Matrix &b) {
    Matrix res;
    res.matrix.resize(a.matrix.size());
    for (int i = 0; i < a.matrix.size(); ++i) {
        for (int j = 0; j < b.matrix[0].size(); ++j) {
            int sum = 0;
            for (int k = 0; k < a.matrix[0].size(); ++k) {
                sum += a.matrix[i][k] * b.matrix[k][j];
            }
            res.matrix[i].push_back(sum);
        }
    }
    return res;
}
