#include "ColorPallete.hpp"
#include <string>
#include <iostream>
#include <fstream>

std::string readFileContent(const std::string& filePath) {
    std::ifstream in(filePath, std::ios::binary);

    if (!in) {}

    auto content = std::string{std::istreambuf_iterator<char>{in}, std::istreambuf_iterator<char>{}};

    if (!in.eof()) {}

    return content;
}

int main() {
    std::string result = readFileContent("lena.bmp");
    bitmap::ColorPallete colors(result.substr(54 , 1078 - 54));
    for (auto i = 0; i < colors._colors.size(); i++) {
        std::cout << colors._colors[i][0] << colors._colors[i][1] << colors._colors[i][2] << std::endl;
    }
}