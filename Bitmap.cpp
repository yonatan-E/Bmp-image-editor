#include "Bitmap.hpp"
#include "BitAdjuster.hpp"
#include <fstream>
#include <iterator>
#include <utility>

namespace bitmap {

    Bitmap::Bitmap(std::string path) : _path(std::move(path)), BitAdjuster(std::move(readFromFile(path))) {
        read();
    }

    Bitmap::Bitmap(const Bitmap& other) : BitAdjuster(other) {
        this->_path = other._path;
        this->_header = new BitmapHeader(*(other._header));
        this->_dibHeader = new BitmapDIBHeader(*(other._dibHeader));
        this->_bitmapArray = new BitmapArray(*(other._bitmapArray));
        this->_colorPallete = new ColorPallete(*(other._colorPallete));
    }

    Bitmap& Bitmap::operator=(const Bitmap& other) {
        if (this == &other) {
		    return *this;
	    }

        reset();

        *this = Bitmap(other); 
	    return *this;
    }

    Bitmap::Bitmap(Bitmap&& other) noexcept : BitAdjuster(std::move(other)) {
        other.setData(nullptr);
        _path = std::exchange(other._path, nullptr);
        _header = std::exchange(other._header, nullptr);
        _dibHeader = std::exchange(other._dibHeader, nullptr);
        _bitmapArray = std::exchange(other._bitmapArray, nullptr);
        _colorPallete = std::exchange(other._colorPallete, nullptr);
    }

    Bitmap& Bitmap::operator=(Bitmap&& other) noexcept {
        if (this == &other) {
		    return *this;
	    }

	    reset();
        
        this->setData(std::move(other.getData()));
        other.setData(nullptr);
        _path = std::exchange(other._path, nullptr);
        _header = std::exchange(other._header, nullptr);
        _dibHeader = std::exchange(other._dibHeader, nullptr);
        _bitmapArray = std::exchange(other._bitmapArray, nullptr);
        _colorPallete = std::exchange(other._colorPallete, nullptr);
        return *this;
    }

    Bitmap::~Bitmap() {
        try {
		    reset();
	    }
	    catch (...) {

	    }
    }

    void Bitmap::read() {
        this->_header = new BitmapHeader(getData().substr(0,14));
        this->_dibHeader = new BitmapDIBHeader(getData().substr(14,40));

        if (this->_dibHeader->getBitsPerPixel() == 8){
            this->_colorPallete = new ColorPallete(getData().substr(54 , this->_header->getOffset() - 54)); 
        }
        else {
            // return nullptr in color pallete if the image is 24-bit
            this->_colorPallete = nullptr; 
        }

         this->_bitmapArray = new BitmapArray(getData().substr(this->_header->getOffset()), this->_dibHeader->getBitsPerPixel()
                ,this->_dibHeader->getHeight(), this->_dibHeader->getWidth(), this->_colorPallete);  
    }

       void Bitmap::write(){

        this->_header->write();
        this->_dibHeader->write();
        this->_colorPallete->write();
        this->_bitmapArray->write();

        std::string result = this->_header->getData() + this->_dibHeader->getData()+
        this->_colorPallete->getData() + this->_bitmapArray->getData();

        writeFileContent(this->_path, result); 
    }


    void Bitmap::turn(){
        _header->turn();
        _dibHeader->turn();
        _bitmapArray->turn();
        if(_colorPallete != nullptr) {
            _colorPallete->turn();
        }
        write();
    }

    void Bitmap::gray() {
        _header->gray();
        _dibHeader->gray();
        _bitmapArray->gray();
        if(_colorPallete != nullptr) {
            _colorPallete->gray();
        }
        write();
    }

    void Bitmap::reset() noexcept {
        delete _header;
        delete _dibHeader;
        delete _bitmapArray;
        delete _colorPallete;
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