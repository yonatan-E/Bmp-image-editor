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

        BitmapHeader(const BitmapHeader& other) = default;
        BitmapHeader& operator=(const BitmapHeader& other) = default;

        BitmapHeader(BitmapHeader&& other) noexcept = default;
        BitmapHeader& operator=(BitmapHeader&& other) noexcept = default;

        ~BitmapHeader() = default;

        virtual void read();
        virtual void write();

        virtual void turn();
        virtual void gray();
};

}