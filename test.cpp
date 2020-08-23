#include "BitAdjuster.hpp"
#include "Bitmap.hpp"


int main(){
    bitmap::Bitmap* bm = new bitmap::Bitmap("lena.bmp");
    bm->read();
    bm->turn();
    bm->write();

}