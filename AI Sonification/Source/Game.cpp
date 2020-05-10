/*
  ==============================================================================

    Game.cpp
    Created: 4 May 2020 12:53:08pm
    Author:  jayb2

  ==============================================================================
*/


#include "Game.h"


Game::Game() : m_shape(0, 0, 0, 0), m_frog(2, 2, 2, 2), isRunning(true) {
    addAndMakeVisible(m_shape);
    addAndMakeVisible(m_frog);
    
}

Game::~Game() {

}

void Game::paint(Graphics& g)
{
    
}

void Game::resized() {
    m_shape.setBounds(getLocalBounds());
}

void Game::update() {
    
}