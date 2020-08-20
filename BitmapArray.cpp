#include "BitmapArray.hpp"
#include <string>

namespace bitmap {

BitmapArray::BitmapArray(const std::string& data) : BitAdjuster(data) {
    // reading the data string into the current object
    this->read();
}

void BitmapArray::read() {
    
}

}