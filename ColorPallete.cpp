#include "ColorPallete.hpp"
#include <string>

namespace bitmap {

ColorPallete::ColorPallete(const std::string& data) : BitAdjuster(std::move(data)) {
    // reading the data string into the current object
    this->read();
}

void ColorPallete::read() {
    uint32_t i = 0;
    while(i < this->getData().size()){
        int color[3] = {bytesToInteger(i, 1), bytesToInteger(i + 1, 1), bytesToInteger(i + 2, 1)};
        this->_colors.push_back(color);
        i += 4;
    }
}

void ColorPallete::addColor(int b, int g, int r){
    int color[3] = {b, g, r};
    this->_colors.push_back(color);
}

void ColorPallete::write(){
    for(int i = 0; i < this->_colors.size() ; i += 4){
        this->setData(this->getData().substr(0, i) + integerToBytes(this->_colors.at(i)[0], 1) +  integerToBytes(this->_colors.at(i)[1], 1)
         +  integerToBytes(this->_colors.at(i)[2], 1) + this->getData().substr(i + 3));
    }
}

}