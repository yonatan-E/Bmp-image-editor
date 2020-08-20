#pragma once

#include "BitAdjuster.hpp"
#include <string>

namespace bitmap {

class BitmapArray : public BitAdjuster {



    public:
        explicit BitmapArray(const std::string& data);

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