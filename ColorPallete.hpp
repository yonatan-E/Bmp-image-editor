#pragma once

#include "BitAdjuster.hpp"
#include <string>

namespace bitmap {

class ColorPallete : public BitAdjuster {


    public:
        explicit ColorPallete(const std::string& data);

        ColorPallete(const ColorPallete& other) = default;
        ColorPallete& operator=(const ColorPallete& other) = default;

        ColorPallete(ColorPallete&& other) noexcept = default;
        ColorPallete& operator=(ColorPallete&& other) noexcept = default;

        ~ColorPallete() = default;

        void read() override;
        void write() override;

        void turn() override;
        void gray() override;
};

}