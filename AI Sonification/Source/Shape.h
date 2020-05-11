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

   Point <int> m_xPos, m_yPos, m_width, m_height;
    Colour m_col;

public:
    //int velocity;

    Shape(int x, int y, int w, int h, Colour col);
    ~Shape();

    Rectangle<int> getShape();

    void jumpLeft();
    void draw(Graphics&);




 };