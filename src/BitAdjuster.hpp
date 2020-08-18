#pragma once

namespace bitmap {

    /**
     * @brief This class is a base class for all of the classes which define
     *        the parts of the bmp file format.
     */
    class BitAdjuster {

    protected: 
         
         virtual void read() = 0;

         virtual void write() = 0;

    public: 

         virtual void turn() = 0;

         virtual void gray() = 0;

    };

}