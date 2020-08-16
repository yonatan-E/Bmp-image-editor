#pragma once
#include <string>


namespace bitmap {

    class BitmapDIBHeader{

    std::string _data; //string data
    int _hsize = 40; // size of header
    int _bitmapWidth = 0; // width of bitmap
    int _bitmapHeight = 0; //height of bitmap
    int _con = 1; //constant(always 1)
    int _bpp = 0; //bits per pixel (8 or 24)
    int _cm = 0; //compression method (no compression, therfore 0)
    int bmsize = 0; //bitmap size;
    int numcolors = 0; //number of colors in color

    public:
        explicit BitmapDIBHeader(std::string data);

        BitmapDIBHeader(const BitmapDIBHeader& other);
        BitmapDIBHeader& operator=(const BitmapDIBHeader& other);

        BitmapDIBHeader(BitmapDIBHeader&& other) noexcept;
        BitmapDIBHeader& operator=(BitmapDIBHeader&& other) noexcept;

        ~BitmapDIBHeader();

    private:
        void parseData(std::string data);

    };

}