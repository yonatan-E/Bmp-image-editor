#include "BitmapHeader.hpp"
#include <string>
#include <cstdint>

namespace bitmap {

BitmapHeader::BitmapHeader(const std::string& data) : BitAdjuster(data) {
    // reading the data string into the current object
    this->read();
}

void BitmapHeader::read() {
    this->_fileSize = this->bytesToInteger(2, 4);
    this->_reserved1 = this->bytesToInteger(6, 2);
    this->_reserved2 = this->bytesToInteger(8, 2);
    this->_offset = this->bytesToInteger(10, 4);
}

void BitmapHeader::write() {
    this->_data = this->_data.substr(0,2) + integerToBytes(this->_fileSize , 4) + this->_data.substr(6, 10)
     + integerToBytes(this->_offset , 4);
}

void BitmapHeader::turn() {

}

void BitmapHeader::gray() {

}

uint32_t BitmapHeader::getOffset() {
    return this->_offset;
}

}