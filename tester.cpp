#include "BitmapHeader.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <cstdint>
#include <cstring>

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

void writeFileContent(const std::string& filePath, const std::string& content) {
  // Opens output-only file (ofstream) in binary mode, and truncates all
  //    existing content from the file.
  std::ofstream out(filePath, std::ios::binary | std::ios::trunc);

  // The file is in a bad state.
  if (!out) {
    // Error here...
  }

  out.write(content.data(), static_cast<std::streamsize>(content.length()));
  if (!out) {
    // Unlikly to happen error here...
  }
}


void intToByte(int n, unsigned char c[4]) {
    c[0] =(unsigned char)(n);
    c[1] = (unsigned char)(n >>  8);
    c[2] = (unsigned char)(n >> 16);
    c[3] = (unsigned char)(n >> 24);
}


int main() {

  std::string f1 = readFileContent("lena-color.bmp");
    char header[4];
    int x = 50;

    std::memcpy(header, &x, 4);
    std::string str = static_cast<char*>(header);
    str = str + (char)0 +  (char)0;

    std::string resultW = f1.substr(0, 14) + str + f1.substr(18);
 
    writeFileContent("lena-color.bmp", resultW); //Writing 50 insted of 40;

    std::string result = readFileContent("lena-color.bmp");

     int pr = *((uint32_t*)(result.substr(14,4).data()));
  
  std::cout << pr << "\n";

  return 0;
}