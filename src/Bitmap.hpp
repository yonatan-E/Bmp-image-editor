#pragma once
#include <string>


namespace bitmap {

class Bitmap: public BitAdjuster {
    
    // the header of the bitmap file
    BitmapHeader _header;
    // the DIB header of the bitmap file
    BitmapDIBHeader _dibHeader;
    // the bitmap array
    BitmapArray _bitmapArray;
    // the colorpallete of the bitmap file
    ColorPallete _colorPallete;

    public:
        explicit Bitmap(std::string path);

        Bitmap(const Bitmap& other);
        Bitmap& operator=(const Bitmap& other);

        Bitmap(Bitmap&& other) noexcept;
        Bitmap& operator=(Bitmap&& other) noexcept;

        ~Bitmap();

        void turn();

        void gray();

    protected:

        void read();

        void write();

    private:

        void reset() noexcept;

};

}