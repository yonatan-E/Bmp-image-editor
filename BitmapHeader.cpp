#include "BitmapHeader.hpp"
#include <string>
#include <cstdint>
#include <cstring>
#include <iostream>

namespace bitmap {

BitmapHeader::BitmapHeader(std::string data) 
    : BitAdjuster(std::move(data)), _fileSize(bytesToInteger<uint32_t>(2)), _reserved1(bytesToInteger<uint16_t>(6)),
    _reserved2(bytesToInteger<uint16_t>(8)), _offset(bytesToInteger<uint32_t>(10)) {}

void BitmapHeader::write() {}

void BitmapHeader::turn() {}

void BitmapHeader::gray() {}

uint32_t BitmapHeader::getOffset() {
    return _offset;
}

}