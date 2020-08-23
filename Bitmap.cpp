#include "Bitmap.hpp"
#include <fstream>
#include <iterator>
#include <utility>

namespace bitmap {

    Bitmap::Bitmap(std::string path) : BitAdjuster(std::move(readFileContent(path))), _path(std::move(path))
    , _header(BitmapHeader(getData().substr(0,14))),  _dibHeader(BitmapDIBHeader(getData().substr(14,40)))
    , _bitmapArray(BitmapArray(getData().substr(_header.getOffset()), getData().substr(54 , _header.getOffset() - 54),
        _dibHeader.getBitsPerPixel(), _dibHeader.getHeight(), _dibHeader.getWidth())) {
        //read();
    }

    void Bitmap::read() {
        // _header = BitmapHeader(getData().substr(0,14));
        // _dibHeader = BitmapDIBHeader(getData().substr(14,40));

        // _bitmapArray = BitmapArray(getData().substr(_header.getOffset()), getData().substr(54 , _header.getOffset() - 54),
        // _dibHeader.getBitsPerPixel(), _dibHeader.getHeight(), _dibHeader.getWidth());  
    }

    void Bitmap::write(){
        
        // activing write() for all of the parts of the bitmap
        _header.write();
        _dibHeader.write();
        _bitmapArray.write();
        
        // setting the new data string to be the data string of the bitmap
        setData(_header.getData() + _dibHeader.getData()
        + _bitmapArray.getColorPallete().getData() + _bitmapArray.getData());

        writeFileContent(_path, getData()); 
    }

    void Bitmap::turn() {
        _header.turn();
        _dibHeader.turn();
        _bitmapArray.turn();
        write();
    }

    void Bitmap::gray() {
        _bitmapArray.gray();
        write();
    }

    std::string Bitmap::readFileContent(const std::string& path) { 
        std::ifstream in(path, std::ios::binary);

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

    void Bitmap::writeFileContent(const std::string& filePath, const std::string& content) {
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