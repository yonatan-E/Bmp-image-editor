#include "BitmapArray.hpp"
#include "Matrix.hpp"
#include <string>
#include <utility>
#include <cstdint>

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
    delete _colors;
    delete _pixels;

    *this = BitmapArray(other); 
	return *this;
}

BitmapArray::BitmapArray(BitmapArray&& other) noexcept : BitAdjuster(std::move(other)) {
    other.setData(nullptr);
    _colors = exchange(other._colors, nullptr);
    _pixels = exchange(other._pixels, nullptr);
    _bitsPerPixel = exchange(other._bitsPerPixel, 0);
    _height = exchange(other._height, 0);
    _width = exchange(other._width, 0);
}

BitmapArray& BitmapArray::operator=(BitmapArray&& other) noexcept {
    if (this == &other) {
		return *this;
	}

	// destroying the allocated fields
    delete _colors;
    delete _pixels;
        
    setData(std::move(other.getData()));
    other.setData(nullptr);
    _colors = exchange(other._colors, nullptr);
    _pixels = exchange(other._pixels, nullptr);
    _bitsPerPixel = exchange(other._bitsPerPixel, 0);
    _height = exchange(other._height, 0);
    _width = exchange(other._width, 0);
    return *this;
}

BitmapArray::~BitmapArray() {
    delete _colors;
    delete _pixels;
}

void BitmapArray::read() {
    if (_bitsPerPixel == 8) {
        for (uint32_t i = 0; i < _height ; i++) {
            for (uint32_t j = 0; j < _width ; j++) {
                _pixels->setAt(i, j, bytesToInteger<uint8_t>(j + i * _width));
            }
            // padding
        }   
    }

    if (_bitsPerPixel == 24) {
        // building new empty ColorPallete
        _colors = new ColorPallete(); 

        uint32_t index = 0;
        for (uint32_t i = 0; i < _height ; i++) {
            for (uint32_t j = 0; j <= _width ; j+=3) {
                _pixels->setAt(i, j, index);
                _colors->add(bytesToInteger<uint8_t>(j + i * _width), bytesToInteger<uint8_t>(j + i * _width + 1),
                bytesToInteger<uint8_t>(j + i * _width + 2));
                index++;
            }
            // padding
        }  
    }
}

void BitmapArray::write() {
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
                setData(getData().substr(0, j + i * _width) + IntegerToBytes<uint8_t>(_colors->getColor(index)[0]) 
                + IntegerToBytes<uint8_t>(_colors->getColor(index)[1]) + IntegerToBytes<uint8_t>(_colors->getColor(index)[2])
                + getData().substr(j + i * _width + 3));
                index++;
        }   
    }
}

void BitmapArray::turn() {
    uint32_t temp = _height;
    _height = _width;
    _width = temp;
    _pixels->turn();
}

void BitmapArray::gray() {
    _colors->gray();
}

}