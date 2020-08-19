#pragma once

#include <string>
#include <cstdint>
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
          * @brief Method that reads the content of the current object into the string
          * 
          */
         virtual void write() = 0;

    public:

         /**
          * @brief The constrtuctor, that creates an object with the given string
          * 
          * @param data 
          */
         BitAdjuster(const std::string& data);

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
         virtual const std::string& getData() const&;

         /**
          * @brief Method that returns the string of the object (rvalue)
          * 
          * @return std::string the string of the object
          */
         virtual std::string&& getData() &&;         

         /**
          * @brief Method that converts a specific part of the string to an unsigned integer
          * 
          * @param index the index where the specific part of the string starts 
          * @param numBytes the size of the specific part, in bytes
          * @return unsigned int the specific part, converted to int
          */
         virtual unsigned int bytesToInteger(int index, int numBytes) const;
    };

}