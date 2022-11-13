#ifndef TGAIMG_H
#define TGAIMG_H

#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

class TGAimg
{

    public:

        //struct for storing pixel color data
        struct Pixel
        {
            //pixel color variables
            unsigned char blue;
            unsigned char green;
            unsigned char red;
            //pixel constructor
            Pixel(unsigned char bval, unsigned char gval, unsigned char rval)
            : blue{bval}, green{gval}, red{rval} { }

        };

        //struct for storing image header data
        struct IMGheader
        {

            char idLength;
            char colorMapType;
            char dataTypeCode;
            short colorMapOrigin;
            short colorMapLength;
            char colorMapDepth;
            short xOrigin;
            short yOrigin;
            short width;
            short height;
            char bitsPerPixel;
            char imageDescriptor;
            
        };

        void loadIMG(string file);//loads image from TGA file
        void exportIMG(string file) const;//exports an image as TGA file
        void getHeader() const; //prints header information
        void blendMultiply(TGAimg& bottom); //blend multiply calling object is the top layer
        void blendSubtract(TGAimg& bottom); //blend subtract calling object is top layer
        void blendScreen(TGAimg& bottom); //blend screen 1 - (1 - A) * (1 - B)
        void blendOverlay(TGAimg& bottom); 
        bool compareIMG(TGAimg& image2);//compares two images for testing
        void addGreen(int value);//adds specified green value to green channel
        void scaleRed(int value);//scales red channel by specified red value
        void scaleBlue(int value);//scales blue channel by specified blue value
        void separateRed();//removes red balanced grey value from image
        void separateBlue();//removes blue balanced grey value from image
        void separateGreen();//removes green balanced grey value from image
        void combineColors(TGAimg& gChannel, TGAimg& rChannel);//combines green channel and red channel to calling blue channel image
        void rotateImage();//rotates an image 180degrees

        private:
            IMGheader imageHeader; //stores header information in custom struct 
            map<int, Pixel> image; //stores pixel information in map


};

#endif