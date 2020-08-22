#include "Bitmap.hpp"
#include <fstream>
#include <iterator>
#include <utility>

namespace bitmap {

    Bitmap::Bitmap(std::string path) 
            : BitAdjuster(std::move(readFromFile(path))), _path(std::move(path)) {
        
        read();
    }

    void Bitmap::read() {
        this->_header = new BitmapHeader(getData().substr(0,14));
        this->_dibHeader = new BitmapDIBHeader(getData().substr(14,40));

        ColorPallete colors;
        if (this->_dibHeader.getBitsPerPixel() == 8) {
            colors = new ColorPallete(getData().substr(54 , this->_header->getOffset() - 54)); 
        }
        else {
            // return nullptr in color pallete if the image is 24-bit
            colors = nullptr;
        }

        this->_bitmapArray = new BitmapArray(getData().substr(this->_header->getOffset()), this->_colorPallete,
        this->_dibHeader->getBitsPerPixel(), this->_dibHeader->getHeight(), this->_dibHeader->getWidth());  
    }

       void Bitmap::write(){
        
        // activing write() for all of the parts of the bitmap
        _header.write();
        _dibHeader.write();
        _bitmapArray.write();
        
        // setting the new data string to be the data string of the bitmap
        setData(_header.getData() + _dibHeader.getData()
        + _bitmapArray.getColorPallete().getData() + _bitmapArray.getData());

        writeFileContent(this->_path, getData()); 
    }


    void Bitmap::turn(){
        _header.turn();
        _dibHeader.turn();
        _bitmapArray.turn();
        write();
    }

    void Bitmap::gray() {
        _bitmapArray.gray();
        write();
    }

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
    
}