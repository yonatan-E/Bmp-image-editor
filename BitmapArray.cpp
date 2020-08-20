#include "BitmapArray.hpp"
#include <string>

namespace bitmap {

BitmapArray::BitmapArray(const std::string& data, uint32_t bpp, uint32_t height, uint32_t width, ColorPallete colors) : BitAdjuster(data) {
    
    this->bitsPerPixel = bpp;
    this->height = height;
    this->width = width;
    this->colors = colors;
    this->pixels(height, width);
    
    // reading the data string into the current object
    this->read();
}

void BitmapArray::read() {

    if(bitsPerPixel == 8){
        for(uint32_t i = 0; i <= height ; i++){
            for(uint32_t j = 0; j <= width ; j++){
                pixels.set(i, j, bytesToInteger(j + i*width, 1));
            }
            //padding
        }   
    }

    if(bitsPerPixel == 24){
        uint32_t index = 0;
        for(uint32_t i = 0; i <= height ; i++){
            for(uint32_t j = 0; j <= width ; j+=3){
                pixels.set(i, j, j + i*width);
                colors.add(bytesToInteger(j + i*width, 1), bytesToInteger(j + i*width + 1, 1), bytesToInteger(j + i*width + 2, 1));
                index++;
            }
            //padding
        }  
    }
}

}