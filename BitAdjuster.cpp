#include "BitAdjuster.hpp"
#include <string>
#include <cstdint>
#include <cstring>

namespace bitmap {

    BitAdjuster::BitAdjuster(const std::string& data) : _data(std::move(data)) {}

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

    std::string integerToBytes(int n, int numBytes){
        std::string str = nullptr;
        char header[4];
        if(numBytes == 1){
            std::memcpy(header, &n, 1);
            std::string str = static_cast<char*>(header);
            return str;
        }
        if(numBytes == 2){
            std::memcpy(header, &n, 2);
            std::string str = static_cast<char*>(header);
            return str;
        }
         if(numBytes == 4){
            std::memcpy(header, &n, 4);
            std::string str = static_cast<char*>(header);
            return str + (char)0 +  (char)0;
        }

        return nullptr;

    }

    const std::string& BitAdjuster::getData() const& {
        return this->_data;
    }

    void BitAdjuster::setData(const std::string& data) {
        this->_data = std::move(data);
    }
}