#include "bmp_tester.hpp"
#include "Bitmap.hpp"
#include "FileHandler.hpp"

using namespace bitmap;

namespace testing {
namespace bmp {

void rotate_image(const std::string& imagePath, const std::string& outputPath) {
    // reading the bitmap data from the file
    std::string data = util::FileHandler::readFileContent(imagePath);

    // creating a bitmap object with the data of the file, and activing its turn() method
    Bitmap bitmap(std::move(data));
    bitmap.turn();

    // writing the bitmap object to the output file
    util::FileHandler::writeFileContent(outputPath, bitmap.getData());
}

void convert_to_grayscale(const std::string& imagePath, const std::string& outputPath) {
    // reading the bitmap data from the file
    std::string data = util::FileHandler::readFileContent(imagePath);

    // creating a bitmap object with the data of the file, and activing its gray() method
    Bitmap bitmap(std::move(data));
    bitmap.gray();

    // writing the bitmap object to the output file
    util::FileHandler::writeFileContent(outputPath, bitmap.getData());
}
}
}