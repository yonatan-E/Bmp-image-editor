#include "BitmapHeader.hpp"
#include <string>
#include <cstdint>

namespace bitmap {

BitmapHeader::BitmapHeader(const std::string& data) : BitAdjuster(std::move(data)) {
    // reading the data string into the current object
    this->read();
}

void BitmapHeader::read() {
    this->_fileSize = this->bytesToInteger(2, 4);
    this->_reserved1 = this->bytesToInteger(6, 2);
    this->_reserved2 = this->bytesToInteger(8, 2);
    this->_offset = this->bytesToInteger(10, 4);
}

void BitmapHeader::write() {}

void BitmapHeader::turn() {}

void BitmapHeader::gray() {}

uint32_t BitmapHeader::getOffset() {
    return this->_offset;
}

}