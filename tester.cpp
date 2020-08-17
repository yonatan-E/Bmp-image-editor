#include "Matrix.hpp"
#include <string>
#include <iostream>

void printMatrix(matrix::Matrix matrix) {
     for (uint32_t i = 0; i < matrix.getHeight(); i++) {
         for (uint32_t j = 0; j < matrix.getWidth(); j++) {
              std::cout << matrix(i, j) << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void initMatrix(matrix::Matrix& matrix) {
    for (uint32_t i = 0; i < matrix.getHeight(); i++) {
        for (uint32_t j = 0; j < matrix.getWidth(); j++) {
            matrix.setAt(i*j, i, j);
        }
    }
}

int main() {
    // creating two matrices
    matrix::Matrix matrix1(4, 4), matrix2(4, 4);

    // initializing the matrices
    initMatrix(matrix1);
    initMatrix(matrix2);


    printMatrix(matrix1);
    printMatrix(matrix2);

    // printing the sum
    printMatrix(matrix1 + matrix2);

    // printing the multiplication
    printMatrix(matrix1 * matrix2);

    // printing the multiplication by scalar
    printMatrix(matrix1 * 2);
    
}