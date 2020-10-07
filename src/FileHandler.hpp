#pragma once

#include <string>

namespace bitmap {

    namespace util {

        /**
         * @brief This class will be in charge of reading and writing from files.
         * 
         */
        class FileHandler {

            public:

                /**
                 * @brief Read the content of a file
                 * 
                 * @param path the path to the file
                 * @return std::string the content of the file
                 */
                static std::string readFileContent(const std::string& filePath);

                /**
                 * @brief Write the content to a file
                 * 
                 * @param filePath the path to the file
                 * @param content the content to write into the file
                 */
                static void writeFileContent(const std::string& filePath, const std::string& content);
        };
    }
}