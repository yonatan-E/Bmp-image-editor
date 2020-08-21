#include "BitmapArray.hpp"
#include <string>
#include "Matrix.hpp"

namespace bitmap {

BitmapArray::BitmapArray(const std::string& data, const ColorPallete& colors, uint32_t bpp, uint32_t height, uint32_t width) 
        : BitAdjuster(std::move(data)), _bitsPerPixel(bpp), _height(height), _width(width) {
    _colors = &colors;
    _pixels = new Matrix(height, width);
    // reading the data string into the current object
    this->read();
}

BitmapArray::BitmapArray(const BitmapArray& other) 
        : BitAdjuster(other), _bitsPerPixel(other._bitsPerPixel), _height(other._height), _width(other._width) {
    _colors = new ColorPallete(*(other._colors));
    _pixels = new Matrix(*(other._pixels));
}

BitmapArray& BitmapArray::operator=(const BitmapArray& other) {
    if (this == &other) {
		    return *this;
	    }

        // destroying the allocated fields
        delete this->_colors;
        delete this->_pixels;

        *this = BitmapArray(other); 
	    return *this;
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