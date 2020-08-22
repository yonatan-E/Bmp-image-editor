#pragma once

#include "BitAdjuster.hpp"
#include "ColorPallete.hpp"
#include "Matrix.hpp"
#include <string>

namespace bitmap {

class BitmapArray : public BitAdjuster {
    // the number of bits per pixel
    uint32_t _bitsPerPixel;
    // the height of the bitmap array
    uint32_t _height;
    // the width of the bitmap array
    uint32_t _width;
    // the color pallate
    ColorPallete _colors;
    // the pixels matrix
    matrix::Matrix _pixels;

    public:

        /**
         * @brief Construct a new Bitmap Array object
         * 
         * @param data the data string
         * @param colors the color pallete (optional - can be nullptr)
         * @param bpp the number of bits per pixel
         * @param height the height of the bmp file
         * @param width the width of the bmp file
         */
        explicit BitmapArray(std::string data, ColorPallete& colors, uint32_t bpp, uint32_t height, uint32_t width);

        /**
         * @brief The copy constructor
         * 
         * @param other the copied object
         */
        BitmapArray(const BitmapArray& other) = default;
        
        /**
         * @brief The copy assignment operator
         * 
         * @param other the copied object
         * @return BitmapArray& the current object
         */
        BitmapArray& operator=(const BitmapArray& other) = default;

        /**
         * @brief The move constructor
         * 
         * @param other the moved object
         */
        BitmapArray(BitmapArray&& other) noexcept = default;

        /**
         * @brief The move assignment operator
         * 
         * @param other the moved object
         * @return BitmapArray& the current object
         */
        BitmapArray& operator=(BitmapArray&& other) noexcept = default;

        /**
         * @brief Destroy the Bitmap Array object
         * 
         */
        ~BitmapArray() = default;

        void read() override;
        void write() override;

        void turn() override;
        void gray() override;
};

}