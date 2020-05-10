/*
  ==============================================================================

    Frog.cpp
    Created: 4 May 2020 12:52:23pm
    Author:  jayb2

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Frog.h"

Frog::Frog(int x, int y, int w, int h) :
    Shape{x, y, w, h}
{
}


Frog::~Frog() {

}

void Frog::setStartPos(int startPosX, int startPosY) {
    startPosX = xPos;
    startPosY = yPos;
    std::cout << "Start Pos X is " << startPosX << std::endl << "Start Pos Y is " << startPosY << std::endl;
}

