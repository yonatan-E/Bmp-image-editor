#pragma once

#include "ErrorCode.h"
#include <string>
#include <stdexcept>

namespace matrix {
    
    /**
     * @brief This class defines an exception which is defined by an error code
     */
    class Exception : public std::runtime_error {
        public:
            Exception(ErrorCode error) : std::runtime_error(error_getErrorMessage(error)) {}
    };
}