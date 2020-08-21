#include "BitmapArray.hpp"
#include <string>

namespace bitmap {

BitmapArray::BitmapArray(const std::string& data, const ColorPallete& colors, uint32_t bpp, uint32_t height, uint32_t width) 
        : BitAdjuster(std::move(data)), colors(colors), bitsPerPixel(bpp), height(height), width(width), pixels(height, width) {
    // reading the data string into the current object
    this->read();
}

void BitmapArray::read() {

    if (bitsPerPixel == 8) {
        for (uint32_t i = 0; i <= height ; i++) {
            for (uint32_t j = 0; j <= width ; j++) {
                pixels.set(i, j, bytesToInteger(j + i * width, 1));
            }
            // padding
        }   
    }

    if (bitsPerPixel == 24) {
        this->colors(); // building new empty ColorPallete

        uint32_t index = 0;
        for (uint32_t i = 0; i <= height ; i++) {
            for (uint32_t j = 0; j <= width ; j+=3) {
                pixels.setAt(i, j, index);
                colors.add(bytesToInteger(j + i * width, 1), bytesToInteger(j + i * width + 1, 1), bytesToInteger(j + i * width + 2, 1));
                index++;
            }
            // padding
        }  
    }
}

void BitmapArray::turn() {
    pixels.turn();
    write();
}

}