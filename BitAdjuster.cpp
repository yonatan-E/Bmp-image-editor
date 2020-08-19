#include "BitAdjuster.hpp"
#include <string>
#include <cstdint>

namespace bitmap {
    BitAdjuster::BitAdjuster(const std::string& data) {
        this->_data = data;
    }

    unsigned int BitAdjuster::bytesToInteger(int index, int numBytes) const {
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

    const std::string& BitAdjuster::getData() const {
        return this->_data;
    }
}