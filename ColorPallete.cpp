#include "ColorPallete.hpp"
#include <string>

namespace bitmap {

ColorPallete::ColorPallete(const std::string& data) : BitAdjuster(std::move(data)) {
    // reading the data string into the current object
    read();
}

void ColorPallete::read() {
    uint32_t i = 0;
    while(i < getData().size()){
        int color[3] = {bytesToInteger<uint8_t>(i), bytesToInteger<uint8_t>(i + 1), bytesToInteger<uint8_t>(i + 2)};
        _colors.push_back(color);
        i += 4;
    }
}

void ColorPallete::write() {
    for (int i = 0; i < this->_colors.size() ; i += 4) {
        setData(getData().substr(0, i) + integerToBytes<uint8_t>(_colors.at(i)[0]) + integerToBytes<uint8_t>(_colors.at(i)[1])
         +  integerToBytes<uint8_t>(_colors.at(i)[2]) + getData().substr(i + 3));
    }
}

void ColorPallete::addColor(int b, int g, int r) {
    int color[3] = {b, g, r};
    _colors.push_back(color);
}

int* ColorPallete::getColor(uint32_t index) {
    return _colors.at(index);
}

void ColorPallete::turn() {}

void ColorPallete::gray() {
    for (int i = 0 ; i < _colors.size() ; i++) {
        uint32_t newColor =  0.2126 * _colors.at(i)[2] + 0.7152 * _colors.at(i)[1] + 0.0722 * _colors.at(i)[0];
        _colors.at(i)[2] = newColor;
        _colors.at(i)[1] = newColor;
        _colors.at(i)[0] = newColor;

    } 
}

}