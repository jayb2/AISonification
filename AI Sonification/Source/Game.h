/*
  ==============================================================================

    Game.h
    Created: 4 May 2020 12:53:08pm
    Author:  jayb2

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "Shape.h"
#include "Frog.h"
#include "Log.h"

class Game : public Component
{
private:
    Shape m_shape;
    Frog m_frog;


public: 
    bool isRunning;
    //int floorHeight;

    
    Game();
    ~Game();

    void update();
    void tick();
    void paint(Graphics&) override;
    void resized() override;

};