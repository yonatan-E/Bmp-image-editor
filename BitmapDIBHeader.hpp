#pragma once

#include "BitAdjuster.hpp"
#include <string>


namespace bitmap {

    class BitmapDIBHeader : public BitAdjuster {

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

        BitmapDIBHeader(const BitmapDIBHeader& other) = default;
        BitmapDIBHeader& operator=(const BitmapDIBHeader& other) = default;

        BitmapDIBHeader(BitmapDIBHeader&& other) noexcept = default;
        BitmapDIBHeader& operator=(BitmapDIBHeader&& other) noexcept = default;

        ~BitmapDIBHeader() = default;

        virtual void read() override;
        virtual void write() override;

        virtual void turn() override;
        virtual void gray() override;
    };

}