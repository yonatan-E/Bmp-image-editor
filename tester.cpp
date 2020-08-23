#include "ColorPallete.hpp"
#include <string>
#include <iostream>
#include <fstream>

std::string readFileContent(const std::string& filePath) {
    std::ifstream in(filePath, std::ios::binary);

    if (!in) {}

    auto content = std::string{std::istreambuf_iterator<char>{in}, std::istreambuf_iterator<char>{}};

    if (!in.eof()) {}
}

int main() {
    
}