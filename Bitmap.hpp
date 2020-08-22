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
    BitmapHeader* _header;
    // the DIB header of the bitmap file
    BitmapDIBHeader* _dibHeader;
    // the bitmap array
    BitmapArray* _bitmapArray;
    // the colorpallete of the bitmap file
    ColorPallete* _colorPallete;

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
        Bitmap(const Bitmap& other);

        /**
         * @brief The copy assignment operator
         * 
         * @param other the copied object
         * @return Bitmap& the current object
         */
        Bitmap& operator=(const Bitmap& other);
 
        /**
         * @brief The move constructor
         * 
         * @param other the moved object
         */
        Bitmap(Bitmap&& other) noexcept;

        /**
         * @brief The move assignment operator
         * 
         * @param other the moved object
         * @return Bitmap& the current object
         */
        Bitmap& operator=(Bitmap&& other) noexcept;

        /**
         * @brief Destroy the Bitmap object
         * 
         */
        ~Bitmap();

        void turn();

        void gray();

    protected:

        void read();

        void write();

    private:
        
        /**
         * @brief Reset the fields of the bitmap object
         * 
         */
        void reset() noexcept;
        
        /**
         * @brief Read the content of a file
         * 
         * @param path the path to the file
         * @return std::string the content of the file
         */
        std::string readFromFile(const std::string& path);

        /**
         * @brief write the content to a file
         * 
         * @param filePath the path to the file
         * @param content the content to write in the file
         */
        void writeFileContent(const std::string& filePath, const std::string& content);
};

}