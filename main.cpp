#include "BitmapHeader.hpp"
#include <iostream>
#include <string>
#include <fstream>

std::string readFileContent(const std::string& filePath) {
    std::ifstream in(filePath, std::ios::binary);

    if (!in) {}

    auto content = std::string{std::istreambuf_iterator<char>{in}, std::istreambuf_iterator<char>{}};

    if (!in.eof()) {}
}

int main() {
    std::string str = readFileContent("lena.bmp");
    bitmap::BitmapHeader bh(str.substr(0, 14));
    std::cout << bh.getOffset();
}