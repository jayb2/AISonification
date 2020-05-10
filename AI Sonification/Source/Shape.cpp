/*
  ==============================================================================

    Shape.cpp
    Created: 4 May 2020 12:51:51pm
    Author:  jayb2

  ==============================================================================
*/

#include "Shape.h"



Shape::Shape(int x, int y, int w, int h) :
    xPos(x),
    yPos(y),
    width(w),
    height(h)
{
}

Shape::~Shape() {

}

void Shape::paint(Graphics& g)
{
    g.fillAll(Colours::darkcyan);

    //Makes the grid lines for rough guidance on what the lanes are
    //May delete later on?
    col = (Colours::white);
    g.setColour(col);
    for (int n = 0; n < 8; ++n)
    {
        g.drawLine((n * 90), 0, (n * 90), 920);
        

    }

    //Makes the lily pads in which frog can jump on
    g.setColour(Colours::darkgreen);
    for (int n = 0; n < 8; ++n)
    {
        g.fillEllipse((n * 90) + 5, 800, 80, 80);
    }
}