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

    int m_xPos, m_yPos, m_width, m_height;
    Colour m_col;
    int m_length, m_random, m_score;

    std::vector<Image> m_images;
    int m_imageToDraw;
public:
    //int velocity;
    bool alive;
    int maxStamina, stamina;
    int score;


    Shape(int x, int y, int w, int h, Colour col);
    Shape(const Shape& other);

    ~Shape();

    Rectangle<int> getShape();

    void random();
    void stamTick();
    void tick(int verticalVelocity);

    virtual void update() = 0;

    void jumpRight();
    void jumpLeft();

    void doubleJumpRight();
    void doubleJumpLeft();

    void draw(Graphics&);

    void loadImage(Image im);
    void setImageIndex(int index);



};