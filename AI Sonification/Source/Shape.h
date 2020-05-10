/*
  ==============================================================================

    Shape.h
    Created: 4 May 2020 12:51:51pm
    Author:  jayb2

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


class Shape : public Component {    

public:

 

    Colour col;
    int xPos, yPos;
    int width, height;
    //int velocity;

    Shape(int x, int y, int w, int h);
    ~Shape();

    
    void paint(Graphics&);
 };