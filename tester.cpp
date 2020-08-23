#include <fstream>
#include <iterator>
#include <utility>
#include "Matrix.hpp"
#include "BitmapArray.hpp"
#include "iostream"

std::string readFileContent(const std::string& filePath) { 
        std::ifstream in(filePath, std::ios::binary);

        if (!in) {
        // Error here...
        }

        auto content = std::string{std::istreambuf_iterator<char>{in},
                             std::istreambuf_iterator<char>{}};

        if (!in.eof()) {
          // Unlikly to happen error here...
        }

        return content;
    }

    void writeFileContent(const std::string& filePath, const std::string& content) {
        std::ofstream out(filePath, std::ios::binary | std::ios::trunc);

        if (!out) {
          // Error here...
        }
  
        out.write(content.data(), static_cast<std::streamsize>(content.length()));
        if (!out) {
          // Unlikly to happen error here...
        }
    }

   
    
    int main(){
        std::string str = readFileContent("lena.bmp");

        std::string strArray = str.substr(1078);
        std::string strColor = str.substr(54, 1078 - 54);

        bitmap::BitmapArray* ba = new bitmap::BitmapArray(strArray, strColor, 8, 512, 512);

        ba->read();

        ba->printMatrix();

        return 0;

    }