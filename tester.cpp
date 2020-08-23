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
    bitmap::ColorPallete colors("");
    for (auto i = 30; i < 80; i++) {
        colors.addColor(i, i-20, i+20);
    }
    for (auto i = 0; i < colors._colors.size(); i++) {
        std::cout << colors._colors[i][0] << " " << colors._colors[i][1] << " " << colors._colors[i][2] << std::endl;
    } std::cout << '\n';

    colors.gray();
    colors.write();

    bitmap::ColorPallete colors2(colors.getData());
    for (auto i = 0; i < colors2._colors.size(); i++) {
        std::cout << colors2._colors[i][0] << " " << colors2._colors[i][1] << " " << colors2._colors[i][2] << std::endl;
    } std::cout << '\n';

}