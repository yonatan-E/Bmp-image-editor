#include "FileHandler.hpp"
#include <fstream>
#include <iterator>

namespace bitmap {
    
    namespace util {

        std::string FileHandler::readFileContent(const std::string& filePath) {
            // opening the file
            std::ifstream in(filePath, std::ios::binary);

            // checking if an error has occured while opening the file
            if (!in) {
                throw std::runtime_error("An error has occured while opening the file");
            }

            // reading the content from the file
            auto content = std::string{std::istreambuf_iterator<char>{in}, std::istreambuf_iterator<char>{}};

            // checking if an error has occured while reading from the file
            if (!in) {
                throw std::runtime_error("An error has occured while reading from the file");
            }

            return content;
        }

        void FileHandler::writeFileContent(const std::string& filePath, const std::string& content) {
            // opening the file
            std::ofstream out(filePath, std::ios::binary | std::ios::trunc);

            // checking if an error has occured while opening the file
            if (!out) {
                throw std::runtime_error("An error has occured while opening the file");
            }

            // writing the data string to the file
            out.write(content.data(), static_cast<std::streamsize>(content.length()));

            // checking if an error has occured while writing to the file
            if (!out) {
                throw std::runtime_error("An error has occured while writing to the file");
            }
        }
    }
}