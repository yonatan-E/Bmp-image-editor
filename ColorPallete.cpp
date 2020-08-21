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

int* ColorPallete::getColor(uint32_t index){
    return _colors.at(index);
}

void ColorPallete::write(){
    for(int i = 0; i < this->_colors.size() ; i += 4){
        this->setData(this->getData().substr(0, i) + integerToBytes(this->_colors.at(i)[0], 1) +  integerToBytes(this->_colors.at(i)[1], 1)
         +  integerToBytes(this->_colors.at(i)[2], 1) + this->getData().substr(i + 3));
    }
}

void ColorPallete::turn(){}

void ColorPallete:: gray(){
    for(int i = 0 ; i < this->_colors.size() ; i ++){
        uint32_t newColor =  0.2126*_colors.at(i)[2] + 0.7152*_colors.at(i)[1] + 0.0722*_colors.at(i)[0];
        _colors.at(i)[2] = newColor;
        _colors.at(i)[1] = newColor;
        _colors.at(i)[0] = newColor;

    } 
}

}