#include "BitAdjuster.hpp"
#include <string>
#include <cstdint>

namespace bitmap {
    unsigned int BitAdjuster::bytesToInteger(int index, int numBytes) {
        if (numBytes == 1) {
            uint8_t* result = (uint8_t*)this->_data.substr(index, numBytes).data();
            return *result;
        } else if (numBytes == 2) {
            uint16_t* result = (uint16_t*)this->_data.substr(index, numBytes).data();
            return *result;
        } else if (numBytes == 4) {
            uint32_t* result = (uint32_t*)this->_data.substr(index, numBytes).data();
            return *result;
        }
    }
}