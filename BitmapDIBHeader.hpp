#pragma once

#include "BitAdjuster.hpp"
#include <string>


namespace bitmap {

    class BitmapDIBHeader : public BitAdjuster {

    uint32_t _hsize = 40; // size of header
    uint32_t _bitmapWidth = 0; // width of bitmap
    uint32_t _bitmapHeight = 0; //height of bitmap
    uint16_t _con = 1; //constant(always 1)
    uint16_t _bpp = 0; //bits per pixel (8 or 24)
    uint32_t _cm = 0; //compression method (no compression, therfore 0)
    uint32_t _bmsize = 0; //bitmap size;
    uint32_t _numcolors = 0; //number of colors in color

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