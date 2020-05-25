/*
  ==============================================================================

    Fish.cpp
    Created: 17 May 2020 5:04:36pm
    Author:  jayb2

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Fish.h"

Fish::Fish(int x, int y, int w, int h, Colour col) :
    Shape{ x, y, w, h, col }
{
    loadImage(ImageCache::getFromMemory(BinaryData::Fish_1_png, BinaryData::Fish_1_pngSize));
    loadImage(ImageCache::getFromMemory(BinaryData::Fish_R_png, BinaryData::Fish_R_pngSize));
    loadImage(ImageCache::getFromMemory(BinaryData::Fish_L_png, BinaryData::Fish_L_pngSize));


    setImageIndex(0);
}

Fish::Fish(const Fish& other) :
    Shape(other),
    m_isActive(other.m_isActive)
{
};

Fish::~Fish() {

}
void Fish::update() {

    static int frameCount = 0;

    int val = frameCount % 80;

    if (val < 20) {
        setImageIndex(0);
    }
    else if (val < 40){
        setImageIndex(1);
    }
    else if (val < 60) {
        setImageIndex(0);
    }
    else if (val < 80) {
        setImageIndex(2);
    }
    else {
        val = 0;
    }
    ++frameCount;

};
