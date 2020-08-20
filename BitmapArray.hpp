#pragma once

#include "BitAdjuster.hpp"
#include <string>

namespace bitmap {

class BitmapArray : public BitAdjuster {

    uint32_t bitsPerPixel;
    uint32_t height;
    uint32_t width;
    ColorPallete colors;
    Matrix pixels;

    public:
        explicit BitmapArray(const std::string& data, const ColorPallete& colors, uint32_t bpp, uint32_t height, uint32_t width);

        BitmapArray(const BitmapArray& other) = default;
        BitmapArray& operator=(const BitmapArray& other) = default;

        BitmapArray(BitmapArray&& other) noexcept = default;
        BitmapArray& operator=(BitmapArray&& other) noexcept = default;

        ~BitmapArray() = default;

        void read() override;
        void write() override;

        void turn() override;
        void gray() override;
};

}