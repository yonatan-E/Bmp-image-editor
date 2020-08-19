#include "BitmapHeader.hpp"
#include <string>

namespace bitmap {

BitmapHeader::BitmapHeader(const std::string& data) : BitAdjuster(data) {
    // reading the data string into the current object
    this->read();
}

}