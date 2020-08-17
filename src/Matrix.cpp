#include "Matrix.h"
#include "Matrix.hpp"
#include "ErrorCode.hpp"
#include <utility>

namespace matrix {
    
    Matrix::Matrix(uint32_t height, uint32_t width) {
        ErrorCode error = matrix_create(&this->_decorated, height, width);
        if (!error_isSuccess(error)) {
            throw Exception(error);
        }
    }

    Matrix::Matrix(const Matrix& other) {
        ErrorCode error = matrix_copy(&this->_decorated, other._decorated);
        if (!error_isSuccess(error)) {
            throw Exception(error);
        }
    }

    Matrix& Matrix::operator=(const Matrix& other) {
        if (this == &other) {
		    return *this;
	    }

	    // Use the copy constructor and move assignment operator
	    *this = Matrix(other); 
	    return *this;
    }

    Matrix::Matrix(Matrix&& other) noexcept {
        this->_decorated = std::exchange(other._decorated, nullptr);
    }

    Matrix& Matrix::operator=(Matrix&& other) noexcept {
        if (this == &other) {
            return *this;
        }

	    this->_decorated = std::exchange(other._decorated, nullptr);
	    return *this;
    }   

    Matrix::~Matrix() {
        matrix_destroy(this->_decorated);
    }

    uint32_t Matrix::getHeight() {
        uint32_t height;
        ErrorCode error = matrix_getHeight(this->_decorated, &height);
        if (!error_isSuccess(error)) {
            throw Exception(error);
        }
        return height;
    }

    uint32_t Matrix::getWidth() {
        uint32_t width;
        ErrorCode error = matrix_getHeight(this->_decorated, &width);
        if (!error_isSuccess(error)) {
            throw Exception(error);
        }
        return width;
    }
}