/*
  ==============================================================================

    Game.cpp
    Created: 4 May 2020 12:53:08pm
    Author:  jayb2

  ==============================================================================
*/


#include "Game.h"


Game::Game() :m_shape(0, 0, 0, 0, Colours::white), m_frog(105, 810, 60, 60, Colours::hotpink), m_log(105, -500, 60, 200, Colours::sandybrown), m_log2(0, 0, 0, 0, Colours::sandybrown) {
    addAndMakeVisible(m_shape);
    addMouseListener(this, true);
    addKeyListener(this);
    setWantsKeyboardFocus(true);
}

Game::~Game() {

}

void Game::update() {
    
    repaint();
    m_frog.stamTick();
    m_log.tick(5);
 

    if (m_frog.getShape().intersects(m_log.getShape())) {
        m_frog.alive = false;
        DBG("dead");
    }
}

void Game::tick() {

}

void Game::mouseDown(const MouseEvent& event) {

}

bool Game::keyPressed(const KeyPress& key, Component* originatingComponent) {

    if (key.getTextCharacter() == 'd') {
        //DBG("right");
        m_frog.jumpRight();
    }

    if (key.getTextCharacter() == 'a') {
        //DBG("left");
        m_frog.jumpLeft();
    }

    if (key.getTextCharacter() == 'e') {
        //DBG("double right");
        m_frog.doubleJumpRight();
    }
    
    if (key.getTextCharacter() == 'q') {
        //DBG("double left");
        m_frog.doubleJumpLeft();
    }
    return true;
}

void Game::paint(Graphics& g)
{
    g.fillAll(Colours::darkcyan);

    //Makes the grid lines for rough guidance on what the lanes are
    //May delete later on?
    g.setColour(Colours::white);
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
    
    //Draws the frog providing it's alive
    /*if (m_frog.alive) {
        m_frog.draw(g);
    }*/
    m_frog.draw(g);

    //Draws the logs
    m_log.draw(g);

}

void Game::resized() {
    m_shape.setBounds(getLocalBounds());
}


