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
    Log{ x, y, w, h, col }
{
}

Fish::Fish(const Fish& other) :
    Log(other),
    m_isActive(other.m_isActive)
{
};

Fish::~Fish() {

}
void Fish::update() {

};
