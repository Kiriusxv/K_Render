#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) {
    bool steep = false;
    if(std::abs(x0 -x1)< std::abs(y0-y1)){
        std::swap(x0,y0);
        std::swap(x1,y1);
        steep = true;
    }
    
    if(x0>x1){
        std::swap(x0,x1);
        std::swap(y0,y1);
    }
    int dx=x1-x0;
    int dy=std::abs(y1-y0);
    int derror2 =dy*2;
    int error2 = 0;
    int y=y0;


    for(int x = x0;x<=x1;x++){
        if(steep){
            image.set(y,x,color);

        }else
        image.set(x,y,color);
    }
    error2 += derror2;
    if(error2>dx){
        y+=(y1>y0?1:-1);
        error2 -= dx*2;
    }

    // for(int x=x0;x<=x1;x++){
    //     float t=(x-x0)/(float)(x1-x0);
    //     int y = y0*(1-t)+ y1*t;
    //     if(steep){
    //         image.set(y,x,color);
    //     }else{
    //         image.set(x,y,color);
    //     }
    // }

}

int main(int argc, char** argv) {
    TGAImage image(100, 100, TGAImage::RGB);
    for(int i=0;i<20000;i++){
    line(i, 20, 80, 40, image, white);
    line(20,i,40,80,image,red);
    }
    
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}
