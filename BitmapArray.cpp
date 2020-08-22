#include "BitmapArray.hpp"
#include "Matrix.hpp"
#include <string>
#include <utility>
#include <cstdint>

namespace bitmap {

BitmapArray::BitmapArray(std::string data, ColorPallete& colors, uint32_t bpp, uint32_t height, uint32_t width) 
        : BitAdjuster(std::move(data)), _colors(std::move(colors)), _pixels(height, width),
         _bitsPerPixel(bpp), _height(height), _width(width) {
    // reading the data string into the current object
    this->read();
}

void BitmapArray::read() {
    if (_bitsPerPixel == 8) {
        for (uint32_t i = 0; i < _height ; i++) {
            for (uint32_t j = 0; j < _width ; j++) {
                _pixels.setAt(i, j, bytesToInteger<uint8_t>(j + i * _width));
            }
            // padding
        }   
    }

    if (_bitsPerPixel == 24) {
        // building new empty ColorPallete
        _colors = ColorPallete(); 

        uint32_t index = 0;
        for (uint32_t i = 0; i < _height ; i++) {
            for (uint32_t j = 0; j <= _width ; j+=3) {
                _pixels.setAt(i, j, index);
                _colors.addColor(bytesToInteger<uint8_t>(j + i * _width), bytesToInteger<uint8_t>(j + i * _width + 1),
                bytesToInteger<uint8_t>(j + i * _width + 2));
                index++;
            }
            // padding
        }  
    }
}

void BitmapArray::write() {
    // activing the write() function of the color pallete
    _colors.write();

    if (_bitsPerPixel == 8) {
        for (uint32_t i = 0; i < _height ; i++) {
            for (uint32_t j = 0; j < _width ; j++) {
                setData(getData().substr(0, j + i * _width) + IntegerToBytes<uint8_t>(_pixels(i, j))
                + getData().substr(j + i * _width + 1));
            }
        }   
    }

    if (_bitsPerPixel == 24) {
        uint32_t index = 0;
        for (uint32_t i = 0; i < _height ; i++) {
            for (uint32_t j = 0; j < _width ; j += 3) {
                setData(getData().substr(0, j + i * _width) + IntegerToBytes<uint8_t>(_colors.getColor(index)[0]) 
                + IntegerToBytes<uint8_t>(_colors.getColor(index)[1]) + IntegerToBytes<uint8_t>(_colors.getColor(index)[2])
                + getData().substr(j + i * _width + 3));
                index++;
            }   
        }
    }
}

void BitmapArray::turn() {
    uint32_t temp = _height;
    _height = _width;
    _width = temp;
    _pixels.turn();
}

void BitmapArray::gray() {
    _colors.gray();
}

const ColorPallete& BitmapArray::getColorPallete() {
    return _colors;
}

}