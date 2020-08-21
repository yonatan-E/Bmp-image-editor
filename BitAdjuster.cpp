#include "BitAdjuster.hpp"
#include <string>
#include <cstdint>
#include <cstring>

namespace bitmap {

    BitAdjuster::BitAdjuster(const std::string& data) : _data(std::move(data)) {}

    template <typename T>
    T BitAdjuster::bytesToInteger(int index) const{
            T* result = (T*)this->_data.substr(index, sizeof(T)).data();
            return *result;
    }

     template <typename T>
     std::string BitAdjuster::integerToBytes(unsigned int n) const{
         std::string str = nullptr;
         char header[4];
         std::memcpy(header, &n, sizeOf(T));
         std::string str = static_cast<char*>(header);
         return str;
    }

    const std::string& BitAdjuster::getData() const {
        return this->_data;
    }

    void BitAdjuster::setData(const std::string& data) {
        this->_data = std::move(data);
    }
}