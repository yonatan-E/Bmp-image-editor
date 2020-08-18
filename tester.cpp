#include "BitmapHeader.hpp"
#include <iostream>
#include <string>
#include "file_reading.cpp"

int main() {
  std::string result = readFileContent("lena.bmp");
  std::cout << result;
  bitmap::BitmapHeader header(result.substr(0, 14));
  std::cout << header._offset;
  return 0;
}