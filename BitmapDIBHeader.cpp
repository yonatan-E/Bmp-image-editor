#include "BitmapDIBHeader.hpp"
#include <string>
#include <cstdint>

namespace bitmap {

BitmapDIBHeader::BitmapDIBHeader(const std::string& data) : BitAdjuster(std::move(data)) {
    // reading the data string into the current object
    this->read();
}

void BitmapDIBHeader::read() {
    this->_bitmapWidth = bytesToInteger<uint32_t>(4);
    this->_bitmapHeight = bytesToInteger<uint32_t>(8);
    this->_bpp = bytesToInteger<uint16_t>(14);
    this->_bmsize = bytesToInteger<uint32_t>(20);
    this->_numcolors = bytesToInteger<uint32_t>(32);
}

void BitmapDIBHeader::write() {
    std::string newData = getData().substr(0,4) + integerToBytes<uint32_t>(this->_bitmapWidth) + integerToBytes<uint32_t>(this->_bitmapHeight)
    + getData().substr(12, 2) + integerToBytes<uint16_t>(this->_bpp) + getData().substr(16, 4) + integerToBytes<uint32_t>(this->_bmsize)
    + getData().substr(24, 8) + integerToBytes<uint32_t>(this->_numcolors) + getData().substr(36);
    setData(newData);
}

void BitmapDIBHeader::turn() {
    uint32_t temp = this->_bitmapHeight;
    this->_bitmapHeight = this->_bitmapWidth;
    this->_bitmapWidth = temp;
}

void BitmapDIBHeader::gray() {}

uint16_t BitmapDIBHeader::getBitsPerPixel() {
    return _bpp;
}

uint32_t BitmapDIBHeader::getHeight() {
    return _bitmapHeight; 
}

uint32_t BitmapDIBHeader::getWidth() {
    return _bitmapWidth;
}

}