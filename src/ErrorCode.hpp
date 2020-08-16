#pragma once

#include "ErrorCode.h"
#include <string>

namespace matrix {
    
    /**
     * @brief This class defines a null pointer exception
     */
    class NullPointerException : public std::exception {
        virtual const char* what() const throw() override {
            return error_getErrorMessage(ERROR_NULL_POINTER);
        }
    };

    /**
     * @brief This class defines a null pointer exception
     */
    class MatrixInvalidOperationException : public std::exception {
        virtual const char* what() const throw() override {
            return error_getErrorMessage(ERROR_MATRIX_INVALID_OPERATION);
        }
    };
}