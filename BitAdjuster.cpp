#include "BitAdjuster.hpp"
#include <string>

namespace bitmap {

    BitAdjuster::BitAdjuster(const std::string& data) : _data(std::move(data)) {}

    const std::string& BitAdjuster::getData() const {
        return this->_data;
    }

    void BitAdjuster::setData(const std::string& data) {
        this->_data = std::move(data);
    }
}