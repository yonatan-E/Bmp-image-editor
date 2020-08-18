#include "BitmapHeader.hpp"
#include <string>

namespace bitmap {

BitmapHeader::BitmapHeader(const std::string& data) {
    // updating the data string
    this->_data = data;
    // reading the data string into the current object
    this->read();
}

}