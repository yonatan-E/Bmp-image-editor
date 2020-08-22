#include "BitmapHeader.hpp"
#include <fstream>
#include <iterator>
#include <utility>

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

int main(){

    std::string str = readFileContent("lena.bmp");
    bitmap::BitmapHeader* bh = new bitmap::BitmapHeader(str.substr(0, 14));
    bh->print();
    bh->turn();
    bh->print();

    

}

