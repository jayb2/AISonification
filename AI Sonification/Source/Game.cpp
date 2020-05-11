/*
  ==============================================================================

    Game.cpp
    Created: 4 May 2020 12:53:08pm
    Author:  jayb2

  ==============================================================================
*/


#include "Game.h"


Game::Game() :m_shape(0, 0, 0, 0, Colours::white), m_frog(105, 810, 60, 60, Colours::pink), m_log(4, 4, 4, 4, Colours::brown), isRunning(true) {
    addAndMakeVisible(m_shape);
}

Game::~Game() {

}

void Game::update() {
    repaint();
}

void Game::mouseDown(const MouseEvent& event) {
   
    m_frog.jumpLeft();

}

void Game::paint(Graphics& g)
{
    m_frog.draw(g);
}

void Game::resized() {
    m_shape.setBounds(getLocalBounds());
}


