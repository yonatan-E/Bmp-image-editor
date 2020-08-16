#pragma once
#include <string>


namespace bitmap {

class Bitmap {
    // the header of the bitmap file
    BitmapHeader _header;
    // the DIB header of the bitmap file
    BitmapDIBHeader _dibHeader;
    // the bitmap array
    BitmapArray _bitmapArray;
    // the path to the bitmap file
    std::string _path;

    public:
        explicit Bitmap(std::string path);

        Bitmap(const Bitmap& other);
        Bitmap& operator=(const Bitmap& other);

        Bitmap(Bitmap&& other) noexcept;
        Bitmap& operator=(Bitmap&& other) noexcept;

        ~Bitmap();

};

}