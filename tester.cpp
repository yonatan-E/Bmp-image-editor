#include "BitmapHeader.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

std::string readFileContent(const std::string& filePath) {
  // Opens input-only file (ifstream) in binary mode.
  std::ifstream in(filePath, std::ios::binary);

  // The file is in a bad state. The error can be retrieved
  //	using the global `errno` in linux (#include <cerrno>).
  if (!in) {
    // Error here...
  }

  // Read the file to a vector. This is not the most effecient
  //	method to read a file.
  auto content = std::string{std::istreambuf_iterator<char>{in},
                             std::istreambuf_iterator<char>{}};

  // After reading the file, it should meet EOF (end of file). If
  //  it did not, it means that an error occurred.
  if (!in.eof()) {
    // Unlikly to happen error here...
  }

  return content;
}

int main() {
  std::string result = readFileContent("lena-color.bmp");
  //  std::cout << result;
  //bitmap::BitmapHeader header(result.substr(0, 14));
  int pr = *((uint32_t*)(result.substr(14, 4).data()));
  std::cout << pr << "\n";
  return 0;
}