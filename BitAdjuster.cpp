#include "BitAdjuster.hpp"
#include <string>
#include <cstring>

namespace bitmap {

    BitAdjuster::BitAdjuster(const std::string& data) : _data(std::move(data)) {}

    const std::string& BitAdjuster::getData() const {
        return this->_data;
    }

    void BitAdjuster::setData(const std::string& data) {
        this->_data = std::move(data);
    }

    template <typename IntType>
    IntType BitAdjuster::bytesToInteger(int index) const {
        IntType* result = static_cast<IntType*>(this->_data.substr(index, sizeof(IntType)).data());
        return *result;
    }

    template <typename IntType>
    std::string BitAdjuster::integerToBytes(unsigned int n) const {
        std::string str = nullptr;
        char header[4];
        std::memcpy(header, &n, sizeof(IntType));
        std::string str = static_cast<char*>(header);
        return str;
    }
}