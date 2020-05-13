/*
  ==============================================================================

    Game.h
    Created: 4 May 2020 12:53:08pm
    Author:  jayb2

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "Frog.h"
#include "Log.h"


class Game : public Component, public KeyListener
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
    bool keyPressed(const KeyPress& key, Component* originatingComponent);
    void paint(Graphics&) override;
    void resized() override;
    


};