#include "Bitmap.h"
#include <fstream>
#include <iterator>
#include <utility>

namespace bitmap {

    Bitmap::Bitmap(std::string path){
        this->_path = path;
        read();
    }

    Bitmap::Bitmap(const Bitmap& other){
        this->_path = other._path;
        this->_header = new BitmapHeader(other._header);
        this->_dibHeader = new BitmapDIBHeader(other._dibHeader);
        this->_bitmapArray = new BitmapArray(other._bitmapArray);
        this->_colorPallete = new ColorPallete(other._colorPallete);
    }

    Bitmap& Bitmap::operator=(const Bitmap& other){
        if (this == &other) {
		    return *this;
	    }

        reset();

        *this = Bitmap(other); 
	    return *this;
    }

    Bitmap::Bitmap(Bitmap&& other) noexcept{

        _path = std::exchange(other._path, nullptr);
        _header = std::exchange(other._header, nullptr);
        _dibHeader = std::exchange(other._dibHeader, nullptr);
        _bitmapArray = std::exchange(other._bitmapArray, nullptr);
        _colorPallete = std::exchange(other._colorPallete, nullptr);
    }
    Bitmap& Bitmap::operator=(Bitmap&& other) noexcept{
        if (this == &other) {
		    return *this;
	    }

	    reset();

        _path = std::exchange(other._path, nullptr);
        _header = std::exchange(other._header, nullptr);
        _dibHeader = std::exchange(other._dibHeader, nullptr);
        _bitmapArray = std::exchange(other._bitmapArray, nullptr);
        _colorPallete = std::exchange(other._colorPallete, nullptr);
        return *this;
    }

    Bitmap::~Bitmap(){
        try {
		    reset();
	    }
	    catch (...) {

	    }
    }

    /**
     * @brief This method reads the .bmp file and cuts it to sections
     * according to the 4 parts, and builds the 4 parts.
     * 
     */
    void Bitmap::read(){
        const std::string &rfpath = _path; 
        std::ifstream in{rfpath, std::ios_base::binary };

        if(!in){
            throw "Error: can't read file";
        }

        std::string header;
        in.read((char*)&header, 14);
        this->_header = new BitmapHeader(header);

         std::string dibheader;
        in.read((char*)&dibheader, 40);
        this->_header = new BitmapHeaderdib(header);



        //NEED TO IMPLEMENT
    }

    /**
     * @brief This method writes the given 4 parts into
     * one whole .bmp file.
     * 
     */
    void Bitmap::write(){
        const std::string &rfpath = _path; 
        std::ifstream in{rfpath, std::ios_base::binary };

        //NEED TO IMPLEMENT
    }

    /**
     * @brief This method turns the bitmap 90 degrees.
     * 
     */
    void Bitmap::turn(){
        _header->turn();
        _dibHeader->turn();
        _bitmapArray->turn();
        if( _colorPallete != nullptr){
            _colorPallete -> turn();
        }
        write();
    }

    /**
     * @brief This method changes the .bmp image to 
     * gray shade colors.
     * 
     */
    void Bitmap::gray(){
        _header->gray();
        _dibHeader->gray();
        _bitmapArray->gray();
        if( _colorPallete != nullptr){
            _colorPallete -> gray();
        }
        write();
    }

    void Bitmap::reset() noexcept{
        delete _header;
        delete _dibHeader;
        delete _bitmapArray;
        delete _colorPallete;

        _path = nullptr;
    }
    
}