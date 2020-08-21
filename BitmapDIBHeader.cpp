#include "BitmapDIBHeader.hpp"
#include <string>

namespace bitmap {

BitmapDIBHeader::BitmapDIBHeader(const std::string& data) : BitAdjuster(data) {
    // reading the data string into the current object
    this->read();
}

void BitmapDIBHeader::read() {
    this->_bitmapWidth = this->bytesToInteger(4, 4);
    this->_bitmapHeight = this->bytesToInteger(8, 4);
    this->_bpp = this->bytesToInteger(14, 2);
    this->_bmsize = this->bytesToInteger(20, 4);
    this->_numcolors = this->bytesToInteger(32, 4);
}

void BitmapDIBHeader::write(){
    std::string newData = getData().substr(0,4) + integerToBytes(this->_bitmapWidth , 4) + integerToBytes(this->_bitmapHeight , 4)
    + getData().substr(12, 2) + integerToBytes(this->_bpp , 2) + getData().substr(16, 4) + integerToBytes(this->_bmsize , 4)
    + getData().substr(24, 8) + integerToBytes(this->_numcolors , 4) + getData().substr(36);
    setData(newData);
}

}