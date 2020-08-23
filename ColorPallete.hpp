#pragma once

#include "BitAdjuster.hpp"
#include <string>
#include <vector>
#include <array>

namespace bitmap {

class ColorPallete : public BitAdjuster {

    public:
        explicit ColorPallete(std::string data);

        ColorPallete() = default;

        ColorPallete(const ColorPallete& other) = default;
        ColorPallete& operator=(const ColorPallete& other) = default;

        ColorPallete(ColorPallete&& other) noexcept = default;
        ColorPallete& operator=(ColorPallete&& other) noexcept = default;

        ~ColorPallete() = default;

        virtual void read() override;
        virtual void write() override;

        virtual void turn() override;
        virtual void gray() override;

        void addColor(int b, int g, int r);

        std::array<int, 3> getColor(uint32_t index);
        // a vector with all of the colors
        std::vector<std::array<int, 3>> _colors; 
};

}