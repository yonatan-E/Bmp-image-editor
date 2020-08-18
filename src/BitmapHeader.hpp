#pragma once

#include "BitAdjuster.hpp"
#include <string>


namespace bitmap {

class BitmapHeader : public BitAdjuster {
    // the file type, which is always 0x4D42
    uint16_t _fileType = 0x4D42; 
    // file size in bytes
    uint32_t _fileSize = 0;
    // reserved 
    uint16_t _reserved1 = 0;
    uint16_t _reserved2 = 0;
    // offset
    uint32_t _offset = 0;

    // the data string
    std::string _data;

    public:
        explicit BitmapHeader(const std::string& data);

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