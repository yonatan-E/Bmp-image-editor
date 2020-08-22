#include "BitmapHeader.hpp"
#include <string>
#include <cstdint>

namespace bitmap {

BitmapHeader::BitmapHeader(std::string data) : BitAdjuster(std::move(data)) {
    // reading the data string into the current object
    this->read();
}

void BitmapHeader::read() {
    this->_fileSize = this->bytesToInteger<uint32_t>(2);
    this->_reserved1 = this->bytesToInteger<uint16_t>(6);
    this->_reserved2 = this->bytesToInteger<uint16_t>(8);
    this->_offset = this->bytesToInteger<uint32_t>(10);
}

void BitmapHeader::write() {}

void BitmapHeader::turn() {}

void BitmapHeader::gray() {}

uint32_t BitmapHeader::getOffset() {
    return this->_offset;
}

}