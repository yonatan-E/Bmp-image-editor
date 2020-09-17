#pragma once

#include "BitAdjuster.hpp"
#include "BitmapHeader.hpp"
#include "BitmapDIBHeader.hpp"
#include "ColorPallete.hpp"
#include "BitmapArray.hpp"
#include <string>

namespace bitmap {

/**
 * @brief This class represents a BMP file.
 * 
 */
class Bitmap: public BitAdjuster {
    
    // the header of the bitmap file
    BitmapHeader m_header;
    // the DIB header of the bitmap file
    BitmapDIBHeader m_dibHeader;
    // the bitmap array
    BitmapArray m_bitmapArray;

    public:

        /**
         * @brief Construct a new Bitmap object
         * 
         * @param data the data string
         */
        Bitmap(std::string data);

        /**
         * @brief Method that writes the content of the object into the string
         * 
         */
        void write() override;

        /**
         * @brief Method that changes the content of the current object according to the turn
         * 
         */
        void turn() override;

        /**
         * @brief Method that changes the content of the current object according to the
                  color changing to gray
         * 
         */
        void gray() override;
};

}