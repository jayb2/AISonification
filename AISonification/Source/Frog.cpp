/*
  ==============================================================================

    Frog.cpp
    Created: 4 May 2020 12:52:23pm
    Author:  jayb2

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Frog.h"

Frog::Frog(int x, int y, int w, int h, Colour col) :
    Shape{ x, y, w, h, col }
{
    //NEED TO WORK ON ANIMATIONS 

    loadImage(ImageCache::getFromMemory(BinaryData::Frog1_png_png, BinaryData::Frog1_png_pngSize));
    loadImage(ImageCache::getFromMemory(BinaryData::Frog2_png_png, BinaryData::Frog2_png_pngSize));
    loadImage(ImageCache::getFromMemory(BinaryData::Frog3_png_png, BinaryData::Frog3_png_pngSize));
    loadImage(ImageCache::getFromMemory(BinaryData::Frog5_png_png, BinaryData::Frog5_png_pngSize));
    loadImage(ImageCache::getFromMemory(BinaryData::Frog6_png_png, BinaryData::Frog6_png_pngSize));
    loadImage(ImageCache::getFromMemory(BinaryData::Frog_7_png_png, BinaryData::Frog_7_png_pngSize));

    setImageIndex(0);
}


Frog::~Frog() {

}

void Frog::paint(Graphics& g) {

}

void  Frog::update() {
  
    
};
