#include "BitmapDIBHeader.hpp"
#include <string>

namespace bitmap {

Bitmap::BitmapDIBHeader(const std::string& data) : BitAdjuster(data) {
    // reading the data string into the current object
    this->read();
}

void Bitmap::read() {
    this->_fileSize = this->bytesToInteger(2, 4);
    this->_reserved1 = this->bytesToInteger(6, 2);
    this->_reserved2 = this->bytesToInteger(8, 2);
    this->_offset = this->bytesToInteger(10, 4);
}

}