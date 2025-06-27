//
// Created by dokto on 11.06.2024.
//

#pragma once
#include "vector"
namespace math{

    class Matrix {
        using VectorInt = std::vector<int>;
        using MatrixInt = std::vector<VectorInt>;
        public:
        Matrix();
        ~Matrix() = default;
        auto createMatrix() -> void;
        auto out() -> void;
        friend Matrix operator*(const Matrix&a, const Matrix& b);
        private:
        MatrixInt matrix;
    };

}
