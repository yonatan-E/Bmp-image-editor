#include "BitmapDIBHeader.hpp"
#include <string>

namespace bitmap {

BitmapDIBHeader::BitmapDIBHeader(const std::string& data) : BitAdjuster(data) {
    // reading the data string into the current object
    this->read();
}

void BitmapDIBHeader::read() {
    this->_bitmapWidth = this->bytesToInteger(18, 4);
    this->_bitmapheight = this->bytesToInteger(22, 4);
    this->_bpp = this->bytesToInteger(28, 2);
    this->_bmsize = this->bytesToInteger(34, 4);
    this->_numcolors = this->bytesToInteger(46, 4);
}

}