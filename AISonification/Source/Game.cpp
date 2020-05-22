/*
  ==============================================================================

    Game.cpp
    Created: 4 May 2020 12:53:08pm
    Author:  jayb2

  ==============================================================================
*/


#include "Game.h"


Game::Game() : m_frog(105, 810, 60, 60, Colours::hotpink) {
    addMouseListener(this, true);
    addKeyListener(this);
    setWantsKeyboardFocus(true);


    m_logs.push_back(Log(105, 0, 60, 200, Colours::darkcyan));
    m_logs.push_back(Log(15, -500, 60, 200, Colours::darkcyan));

    m_fish.push_back(Fish(645, 0, 60, 100, Colours::darkcyan));
    m_fish.push_back(Fish(285, -314, 60, 100, Colours::darkcyan));
    m_fish.push_back(Fish(465, -627, 60, 100, Colours::darkcyan));
    m_fish.push_back(Fish(15, -940, 60, 100, Colours::darkcyan));
}

Game::~Game() {

}


void Game::update() {

   repaint();
   m_frog.stamTick();
   if (m_frog.alive) {
       for (int n = 0; n < m_logs.size(); ++n) {
           m_logs[n].tick(5);
       }

       for (int n = 0; n < m_fish.size(); ++n) {
           m_fish[n].tick(4);
       }
   }
    static int logFrame = 0;
    ++logFrame;
    m_logFrame = (logFrame / 1000);

    for (int n = 0; n < m_logs.size(); ++n) {
        if (m_frog.getShape().intersects(m_logs[n].getShape()) && m_frog.alive == true) {
            m_frog.alive = false;
            //m_midiManager.triggerNote(1, 55, 100, 4);

            m_midiManager.setChord(-3);
            DBG("dead");
            
        }
    }
    //every second


    if (logFrame % 60 == 0) {

        for (int n = 0; n < m_logs.size(); ++n) {
            if (m_logs[n].isActive() == false) {
                m_logs[n].activate();
                break;
            }
        }
    }
}

void Game::tick() {

}

void Game::setNote(int m_note) {

    //Turns note on
    //auto message = MidiMessage::noteOn(10, m_note, 1.0f);

    //Turns note off
 //   auto message = MidiMessage::noteOff(10, m_note, 1.0f);
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
    g.setColour(Colours::cyan);
    for (int n = 0; n < 8; ++n)
    {
        g.drawLine((n * 90), 0, (n * 90), 920);
    }

    for (int n = 0; n < m_fish.size(); ++n) {
        m_fish[n].draw(g);
    }

    //Draws the logs
    for (int n = 0; n < m_logs.size(); ++n) {
        if (m_logs[n].isActive()) {
            m_logs[n].draw(g);
        }
    }

    //Makes the lily pads in which frog can jump on
    g.setColour(Colours::darkgreen);
    for (int n = 0; n < 8; ++n)
    {
        g.fillEllipse((n * 90) + 5, 800, 80, 80);
    }

    //Draws the frog providing it's alive
    m_frog.draw(g);



}




