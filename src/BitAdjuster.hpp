#pragma once

namespace bitmap {

    class BitAdjuster{

    protected: 

         virtual void read() = 0;

         virtual void write() = 0;

    public: 

         virtual void turn() = 0;

         virtual void gray() = 0;

    };

}