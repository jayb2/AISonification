/*
  ==============================================================================

    Game.h
    Created: 4 May 2020 12:53:08pm
    Author:  jayb2

  ==============================================================================
*/

#pragma once

class Game : public Component
{
public: 
    bool isRunning;
    int floorHeight;

    
    void update();
    void tick();
    void paint(Graphics&) override;
    void resized() override;

};