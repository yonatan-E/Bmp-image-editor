#pragma once

#include "BitAdjuster.hpp"
#include "BitmapHeader.hpp"
#include "BitmapDIBHeader.hpp"
#include "ColorPallete.hpp"
#include "BitmapArray.hpp"
#include <string>


namespace bitmap {

class Bitmap: public BitAdjuster {
    
    // the header of the bitmap file
    BitmapHeader _header;
    // the DIB header of the bitmap file
    BitmapDIBHeader _dibHeader;
    // the bitmap array
    BitmapArray _bitmapArray;
    // the path to the bmp file
    std::string _path;

    public:

        /**
         * @brief Construct a new Bitmap object
         * 
         * @param path the path to the bitmap file
         */
        explicit Bitmap(std::string path);

        /**
         * @brief The copy constructor
         * 
         * @param other the copied object
         */
        Bitmap(const Bitmap& other) = default;

        /**
         * @brief The copy assignment operator
         * 
         * @param other the copied object
         * @return Bitmap& the current object
         */
        Bitmap& operator=(const Bitmap& other) = default;
 
        /**
         * @brief The move constructor
         * 
         * @param other the moved object
         */
        Bitmap(Bitmap&& other) noexcept = default;

        /**
         * @brief The move assignment operator
         * 
         * @param other the moved object
         * @return Bitmap& the current object
         */
        Bitmap& operator=(Bitmap&& other) noexcept = default;

        /**
         * @brief Destroy the Bitmap object
         * 
         */
        ~Bitmap() = default;
        
        /**
         * @brief Method that reads the content of the string into the current object
         * 
         */
        virtual void read() override;

        /**
         * @brief Method that writes the content of the object into the string
         * 
         */
        virtual void write() override;

        /**
         * @brief Method that changes the content of the current object according to the turn
         * 
         */
        virtual void turn() override;

        /**
         * @brief Method that changes the content of the current object according to the
                  color changing to gray
         * 
         */
        virtual void gray() override;

        /**
         * @brief Read the content of a file
         * 
         * @param path the path to the file
         * @return std::string the content of the file
         */
        std::string readFileContent(const std::string& path);

        /**
         * @brief write the content to a file
         * 
         * @param filePath the path to the file
         * @param content the content to write in the file
         */
        void writeFileContent(const std::string& filePath, const std::string& content);
};

}