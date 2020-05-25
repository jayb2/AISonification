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
    m_score(0),
    m_imageToDraw(-1)
{

}

Shape::Shape(const Shape& other) :
    m_xPos(other.m_xPos),
    m_yPos(other.m_yPos),
    m_width(other.m_width),
    m_height(other.m_height),
    m_col(other.m_col),
    alive(other.alive),
    maxStamina(other.maxStamina),
    stamina(other.stamina),
    m_score(other.m_score),
    m_imageToDraw(other.m_imageToDraw),
    m_images(other.m_images)
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

        if (alive) {
            m_score++;
            score = m_score;
            //DBG(score);
        }
    }
    update();
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

    if (m_xPos < 554 && stamina > 0) {
        m_xPos += 180;
        --stamina;
    }
    else if (stamina <= 0) {
        DBG("you outta stamina fool");
    }
}

void Shape::doubleJumpLeft() {

    if (m_xPos > 106 && stamina > 0) {
        m_xPos -= 180;
        --stamina;
    }
    else if (stamina <= 0) {
        DBG("you outta stamina fool");
    }
}

void Shape::draw(Graphics& g)
{


    //if (!alive)return;
    g.saveState();
    g.setColour(m_col);
    g.fillRect(getShape());
    if (m_imageToDraw >= 0 && m_images.size() > 0) {
        g.drawImage(m_images[m_imageToDraw], getShape().toFloat());
    }


    g.restoreState();
}


void Shape::loadImage(Image im) {
    m_images.push_back(im);
}
void Shape::setImageIndex(int index) {

    if (index >= 0 && index < m_images.size()) {

        m_imageToDraw = index;

    }

}