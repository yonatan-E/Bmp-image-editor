#include "BitmapArray.hpp"
#include "ColorPallete.hpp"
#include "Matrix.hpp"
#include "ColorPallete.hpp"
#include <string>
#include <utility>
#include <cstdint>

namespace bitmap {

BitmapArray::BitmapArray(std::string array_data, std::string color_data, uint32_t bpp, uint32_t height, uint32_t width) 
        : BitAdjuster(std::move(array_data)), _colors(color_data), _pixels(height, width),
         _bitsPerPixel(bpp), _height(height), _width(width) {
    // reading the data string into the current object
    this->read();
}

void BitmapArray::read() {
    if (_bitsPerPixel == 8) {
        int index = 0;
        for (uint32_t i = 0; i < _height ; i++) {
            for (uint32_t j = 0; j < _width ; j++) {
                _pixels.setAt(i, j, bytesToInteger<uint8_t>(index));
                index++;
            }
            // padding
        }   
    }

    if (_bitsPerPixel == 24) {
        uint32_t index = 0, runner = 0; 
        // iterating over the data string and initializing the color pallete and the matrix
        for (uint32_t i = 0; i < _height; i++) {
            for (uint32_t j = 0; j < _width; j++) {
                // adding the current index to the exact place in the matrix
                _pixels.setAt(i, j, index);
                // adding the color to the color pallete
                _colors.addColor(bytesToInteger<uint8_t>(runner),bytesToInteger<uint8_t>(runner + 1),
                bytesToInteger<uint8_t>(runner + 2));
                runner += 3;
                index++;
            }
        }  
    }
}

void BitmapArray::write() {
    if (_bitsPerPixel == 8) {
        // activing the write() function of the color pallete
        _colors.write();
        for (uint32_t i = 0; i < _height ; i++) {
            for (uint32_t j = 0; j < _width ; j++) {
                setData(getData().substr(0, j + i * _width) + integerToBytes<uint8_t>(_pixels(i, j))
                + getData().substr(j + i * _width + 1));
            }
        }   
    }

    if (_bitsPerPixel == 24) {
        std::string newData = "";
        // iterating over the matrix and adding the colors of all of the pixels to the string
        for (uint32_t i = 0; i < _height; i++) {
            for (uint32_t j = 0; j < _width; j++) {
                newData += integerToBytes<uint8_t>(_colors.getColor(_pixels(i, j))[0]) 
                + integerToBytes<uint8_t>(_colors.getColor( _pixels(i, j))[1]) 
                + integerToBytes<uint8_t>(_colors.getColor(_pixels(i, j))[2]);
            }
            // for padding
            for (uint32_t k = 0; k < _width % 4; k++) {
                newData += integerToBytes<uint8_t>(0x00); 
            }   
        }
        // setting the new data
        setData(newData); 
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

