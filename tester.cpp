#include "Matrix.hpp"
#include <string>
#include <iostream>

namespace matrix {
    void printMatrix(Matrix matrix) {
        for (uint32_t i = 0; i < matrix.getHeight(); i++) {
            for (uint32_t j = 0; j < matrix.getWidth(); j++) {
                std::cout << matrix(i, j) << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    void initMatrix(Matrix matrix) {
        for (uint32_t i = 0; i < matrix.getHeight(); i++) {
            for (uint32_t j = 0; j < matrix.getWidth(); j++) {
                matrix.setAt(i*j, i, j);
            }
        }
    }
}

int main() {
    matrix::Matrix matrix(4, 4);
    matrix::printMatrix(matrix);
    matrix::initMatrix(matrix);
    matrix::printMatrix(matrix);
}