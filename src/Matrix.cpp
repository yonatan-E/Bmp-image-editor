#include "Matrix.h"
#include "Matrix.hpp"
#include "ErrorCode.hpp"

namespace matrix {
    
    Matrix::Matrix(uint32_t height, uint32_t width) {
        ErrorCode error = matrix_create(&this->_decorated, height, width);
        if (!error_getErrorMessage(error)) {
            throw NullPointerException();
        }
    }

    Matrix::Matrix(const Matrix& other) {
        ErrorCode error = matrix_copy(&this->_decorated, other._decorated);
        if (!error_getErrorMessage(error)) {
            throw NullPointerException();
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
}