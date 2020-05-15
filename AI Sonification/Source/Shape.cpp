/*
  ==============================================================================

    Shape.cpp
    Created: 4 May 2020 12:51:51pm
    Author:  jayb2

  ==============================================================================
*/

#include "Shape.h"



Shape::Shape(int x, int y, int w, int h, Colour col) :
    m_xPos(x),
    m_yPos(y),
    m_width(w),
    m_height(h),
    m_col(col),
    alive(true),
    maxStamina(1),
    stamina(maxStamina),
    m_score(0)

{

}

Shape::~Shape() {

}

Rectangle<int> Shape::getShape() {
    return Rectangle<int>(m_xPos, m_yPos, m_width, m_height);

}

void Shape::random() {
    srand((unsigned)time(0));
    int logXPos[] = { 15, 105, 195, 285, 375, 465, 555, 645 };
    m_length = sizeof(logXPos) / sizeof(int);
    m_random = logXPos[rand() % m_length];
}

void Shape::stamTick() {
    static int frameCount = 0;
    ++frameCount;

    if (frameCount % 100 == 0) {
        ++stamina;
        if (stamina > maxStamina) stamina = maxStamina;
    }

    //DBG(frameCount);
}

void Shape::tick(int verticalVelocity) {
    m_yPos += verticalVelocity;
    if (m_yPos > 1000) {
        m_yPos = -300;
        
        random();
        m_xPos = m_random;
        DBG(m_random);

        if (alive) {
            m_score++;
            DBG(m_score);
        }
    }
    //DO bounds checking here.. do I go offscreen
}

void Shape::jumpRight() {
    if (m_xPos < 646) {
        m_xPos += 90;
        if (m_xPos > 645) {
            m_xPos = 15;
        }
    }
    //DBG("new frog pos ");
    //DBG(m_xPos);
}

void Shape::jumpLeft() {
    if (m_xPos > 14) {
        m_xPos -= 90;
        if (m_xPos < 15) {
            m_xPos = 645;
        }
    }
    //DBG("new frog pos ");
    //DBG(m_xPos);
}

void Shape::doubleJumpRight() {
 
    if (m_xPos < 556 && stamina > 0) {
        m_xPos += 180;
        --stamina;
    }
    else if (stamina <= 0) {
        DBG("you outta stamina fool");
    }
}

void Shape::doubleJumpLeft() {
    
    if (m_xPos > 105 && stamina > 0) {
        m_xPos -= 180;
        --stamina;
    }
    else if (stamina <= 0) {
        DBG("you outta stamina fool");
    }
}

void Shape::draw(Graphics& g)
{


    if (!alive)return;
    g.saveState();
    g.setColour(m_col);
    g.fillRect(getShape());
    g.restoreState();
}

