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
    Log m_log;

public: 
    bool isRunning;
    //int floorHeight;
    int logRunning;


    
    Game();
    ~Game();

    void update();
    void tick();
    void mouseDown(const MouseEvent& event);
    void paint(Graphics&) override;
    void resized() override;


};