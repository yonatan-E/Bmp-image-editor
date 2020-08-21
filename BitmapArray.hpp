#pragma once

#include "BitAdjuster.hpp"
#include <string>

namespace bitmap {

class BitmapArray : public BitAdjuster {

    uint32_t _bitsPerPixel;
    uint32_t _height;
    uint32_t _width;
    ColorPallete* _colors;
    Matrix* _pixels;

    public:
        explicit BitmapArray(const std::string& data, const ColorPallete& colors, uint32_t bpp, uint32_t height, uint32_t width);

        BitmapArray(const BitmapArray& other);
        BitmapArray& operator=(const BitmapArray& other);

        BitmapArray(BitmapArray&& other) noexcept;
        BitmapArray& operator=(BitmapArray&& other) noexcept;

        ~BitmapArray();

        void read() override;
        void write() override;

        void turn() override;
        void gray() override;
};

}