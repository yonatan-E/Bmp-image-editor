#include "ColorPallete.hpp"
#include <string>
#include <array>

namespace bitmap {

ColorPallete::ColorPallete(std::string data) : BitAdjuster(std::move(data)) {
    // reading the data string into the current object
    read();
}

void ColorPallete::read() {
    uint32_t i = 0;
    while (i < getData().size()) {
        std::array<int, 3> color = {bytesToInteger<uint8_t>(i), bytesToInteger<uint8_t>(i + 1), bytesToInteger<uint8_t>(i + 2)};
        _colors.push_back(color);
        i += 4;
    }
}

void ColorPallete::write() {
    std::string result = "";
    for (int i = 0; i < _colors.size(); i++) {
        result += integerToBytes<uint8_t>(_colors.at(i)[0]) + integerToBytes<uint8_t>(_colors.at(i)[1])
        + integerToBytes<uint8_t>(_colors.at(i)[2]) + integerToBytes<uint8_t>(0x00);
    }
    setData(result);
}

void ColorPallete::addColor(int b, int g, int r) {
    std::array<int, 3> color = {b, g, r};
    _colors.push_back(color);
}

std::array<int, 3> ColorPallete::getColor(uint32_t index) {
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