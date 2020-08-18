#include "BitmapHeader.hpp"
#include <string>
#include <cstdint>

namespace bitmap {

BitmapHeader::BitmapHeader(const std::string& data) {
    // updating the data string
    this->_data = data;
    // reading the data string into the current object
    this->read();
}

void BitmapHeader::read() {
    this->_fileSize = *((int*)(this->_data.substr(2, 4).data()));
    this->_reserved1 = *((int*)(this->_data.substr(6, 2).data()));
    this->_reserved2 = *((int*)(this->_data.substr(8, 2).data()));
    this->_offset = *((int*)(this->_data.substr(10, 4).data()));
}

void BitmapHeader::write() {

}

void BitmapHeader::turn() {

}

void BitmapHeader::gray() {

}

}