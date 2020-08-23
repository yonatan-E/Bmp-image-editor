#pragma once

#include "BitAdjuster.hpp"
#include <string>
#include <vector>
#include <array>

namespace bitmap {

class ColorPallete : public BitAdjuster {
<<<<<<< HEAD
=======
    // a vector with all of the colors
    std::vector<std::array<int, 3>> _colors; 
>>>>>>> bitmap_color_pallete

    public:

        /**
         * @brief Construct a new Color Pallete object
         * 
         * @param data the given data string
         */
        explicit ColorPallete(std::string data);

        /**
         * @brief Construct a new Color Pallete object
         * 
         */
        ColorPallete() = default;

        /**
         * @brief The copy ctor
         * 
         * @param other the copied object
         */
        ColorPallete(const ColorPallete& other) = default;

        /**
         * @brief The copy assignment operator
         * 
         * @param other the copied object
         * @return ColorPallete& the current object
         */
        ColorPallete& operator=(const ColorPallete& other) = default;

        /**
         * @brief The move ctor
         * 
         * @param other the moved object
         */
        ColorPallete(ColorPallete&& other) noexcept = default;

        /**
         * @brief The move assignment operator
         * 
         * @param other the moved object
         * @return ColorPallete& the current object
         */
        ColorPallete& operator=(ColorPallete&& other) noexcept = default;

        /**
         * @brief Destroy the Color Pallete object
         * 
         */
        ~ColorPallete() = default;

<<<<<<< HEAD
        virtual void read() override;
        virtual void write() override;

        virtual void turn() override;
        virtual void gray() override;
=======
        /**
         * @brief Method that reads the content of the string into the current object
         * 
         */
        void read() override;

        /**
         * @brief Method that writes the content of the object into the string
         * 
         */
        void write() override;

        /**
         * @brief Method that changes the content of the current object according to the turn
         * 
         */
        void turn() override;

        /**
         * @brief Method that changes the content of the current object according to the
                  color changing to gray
         * 
         */
        void gray() override;
>>>>>>> bitmap_color_pallete

        /**
         * @brief Method that adds the given color to the color pallete
         * 
         * @param b the blue rank of the color
         * @param g the green rank of the color
         * @param r the red rank of the colot
         */
        void addColor(int b, int g, int r);

<<<<<<< HEAD
        std::array<int, 3> getColor(uint32_t index);
        // a vector with all of the colors
        std::vector<std::array<int, 3>> _colors; 
=======
        /**
         * @brief Get the Color object
         * 
         * @param index the given index
         * @return std::array<int, 3> the color in the given index
         */
        std::array<int, 3> getColor(uint32_t index);
>>>>>>> bitmap_color_pallete
};

}