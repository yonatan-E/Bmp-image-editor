#include "BitmapArray.hpp"
#include <string>

namespace bitmap {

BitmapArray::BitmapArray(const std::string& data, const ColorPallete& colors, uint32_t bpp, uint32_t height, uint32_t width) 
        : BitAdjuster(std::move(data)), _colors(colors), _bitsPerPixel(bpp), _height(height), _width(width), _pixels(height, width) {
    // reading the data string into the current object
    this->read();
}

void BitmapArray::read() {
    if (_bitsPerPixel == 8) {
        for (uint32_t i = 0; i <= _height ; i++) {
            for (uint32_t j = 0; j <= _width ; j++) {
                _pixels->set(i, j, bytesToInteger(j + i * _width, 1));
            }
            // padding
        }   
    }

    if (_bitsPerPixel == 24) {
        _colors = new ColorPallete(); // building new empty ColorPallete

        uint32_t index = 0;
        for (uint32_t i = 0; i <= _height ; i++) {
            for (uint32_t j = 0; j <= _width ; j+=3) {
                _pixels->setAt(i, j, index);
                _colors->add(bytesToInteger(j + i * _width, 1), bytesToInteger(j + i * _width + 1, 1), bytesToInteger(j + i * _width + 2, 1));
                index++;
            }
            // padding
        }  
    }
}

void BitmapArray::turn() {
    _pixels->turn();
}

}