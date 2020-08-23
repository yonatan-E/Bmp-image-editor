#pragma once

#include "BitAdjuster.hpp"
#include <string>
#include <vector>

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

        void read() override;
        void write() override;

        void turn() override;
        void gray() override;

        void addColor(int b, int g, int r);

        int* getColor(uint32_t index);
        // a vector with all of the colors
        std::vector<int[3]> _colors; 
};

}