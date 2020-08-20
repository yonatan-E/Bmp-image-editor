#include "ColorPallete.hpp"
#include <string>

namespace bitmap {

ColorPallete::ColorPallete(const std::string& data) : BitAdjuster(std::move(data)) {
    // reading the data string into the current object
    this->read();
}

void ColorPallete::read() {
    uint32_t i = 0;
    while(i <= this->getData().size()){
        int color[3] = {bytesToInteger(i, 1), bytesToInteger(i + 1, 1), bytesToInteger(i + 2, 1)};
        this->_colors.push_back(color);
        i += 4;
    }
}

}