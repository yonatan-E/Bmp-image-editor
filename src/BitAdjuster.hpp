#pragma once

namespace bitmap {

    /**
     * @brief This class is a base class for all of the classes which define
     *        the parts of the bmp file format.
     */
    class BitAdjuster {

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

    };

}