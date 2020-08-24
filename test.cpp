#include "BitAdjuster.hpp"
#include "Bitmap.hpp"


int main(){
    bitmap::Bitmap bm("lena-color.bmp", "lena-color-copy.bmp");
    bm.turn(); 
}