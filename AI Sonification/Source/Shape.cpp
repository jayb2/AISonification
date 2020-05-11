/*
  ==============================================================================

    Shape.cpp
    Created: 4 May 2020 12:51:51pm
    Author:  jayb2

  ==============================================================================
*/

#include "Shape.h"



Shape::Shape(int x, int y, int w, int h, Colour col) :
    m_xPos(x, y),
    //m_yPos(y),
    m_width(w, h),
    //m_height(h),
    m_col(col)

{

}

Shape::~Shape() {

}

Rectangle<int> Shape::getShape() {
    return Rectangle<int>(m_xPos.x, m_xPos.y, m_width.x, m_width.y);

}

void Shape::jumpLeft() {
    m_xPos.x += 90;
    DBG("new frog pos ");
    DBG(m_xPos.x);
}


void Shape::draw(Graphics& g)
{
    g.fillAll(Colours::darkcyan);

    //Makes the grid lines for rough guidance on what the lanes are
    //May delete later on?
    //m_col = (Colours::white);
    g.setColour(m_col);
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

    g.setColour(m_col);
    g.fillRect(getShape());

}

