#pragma once
#include <string>


namespace bitmap {

class Bitmap {

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