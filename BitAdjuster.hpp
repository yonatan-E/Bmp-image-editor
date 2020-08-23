#pragma once

#include <string>
#include <cstring>
#include <iostream>

namespace bitmap {

    /**
     * @brief This class is a base class for all of the classes which define
     *        the parts of the bmp file format.
     */
    class BitAdjuster {
         
          // the data string
          std::string _data;

    protected: 
         
         /**
          * @brief Method that reads the content of the string into the current object
          * 
          */
          virtual void read() = 0;

         /**
          * @brief Method that writes the content of the object into the string
          * 
          */
          virtual void write() = 0;

    public:

         /**
          * @brief The constrtuctor, that creates an object with the given string
          * 
          * @param data the given data string
          */
          BitAdjuster(std::string data);

         /**
          * @brief Method that changes the content of the current object according to the turn
          * 
          */
          virtual void turn() = 0;

         /**
          * @brief Method that changes the content of the current object according to the
                   color changing to gray
          * 
          */
          virtual void gray() = 0;

         /**
          * @brief Method that returns the string of the object (lvalue)
          * 
          * @return std::string the string of the object
          */
          virtual const std::string& getData() const final;

         /**
          * @brief The data string setter
          * 
          */
          virtual void setData(std::string data) final;           

         /**
          * @brief Method that converts a specific part of the string to an unsigned integer
          * 
          * @tparam IntType the specific type of the integer
          * @param index the index where the specific part of the string starts 
          * @return IntType the specific part, converted to the specific int type
          */
          template <typename IntType>
          IntType bytesToInteger(int index) const {
               IntType* result = (IntType*)(this->_data.substr(index, sizeof(IntType)).data());
               return *result;
          }

         /**
          * @brief Method that converts a integer into a byte sequence in a string.
          * 
          * @tparam IntType the type of the integer 
          * @param n the size of the byte sequence
          * @return std::string the byte sequence represented by a string
          */
          template <typename IntType> 
          std::string integerToBytes(unsigned int n) const {
               std::string str = nullptr;
               char header[4]; 
               std::memcpy(header, &n, sizeof(IntType));
               str = static_cast<char*>(header);
               return str;
          }
    };

}