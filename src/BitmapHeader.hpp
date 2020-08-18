#pragma once

#include "BitAdjuster.hpp"
#include <string>


namespace bitmap {

class BitmapHeader : public BitAdjuster {
    // the file type, which is always 0x4D42
    uint16_t fileType = 0x4D42; 
    // file size in bytes
    uint32_t fileSize = 0;
    // reserved 
    uint16_t reserved1 = 0;
    uint16_t reserved2 = 0;
    uint32_t offset = 0;

    public:
        explicit BitmapHeader(std::string data);

        BitmapHeader(const BitmapHeader& other);
        BitmapHeader& operator=(const BitmapHeader& other);

        BitmapHeader(BitmapHeader&& other) noexcept;
        BitmapHeader& operator=(BitmapHeader&& other) noexcept;

        ~BitmapHeader();

        virtual void read() = 0;
        virtual void write() = 0;

        virtual void turn() = 0;
        virtual void gray() = 0;


};

}