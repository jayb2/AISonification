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
#include "Fish.h"
#include <vector>
#include "MidiManager.h"

typedef std::vector<Log> LogVector;
typedef std::vector<Fish> FishVector;

class Game : public Component, public KeyListener
{
private:

    //  Shape m_shape;
    Frog m_frog;
    LogVector m_logs;
    FishVector m_fish;
    int m_numOfLogs, m_logFrame;



    MidiManager m_midiManager;
public:

    Game();
    ~Game();


    void update();
    void tick();

    void setNote(int m_note);

    void mouseDown(const MouseEvent& event);
    bool keyPressed(const KeyPress& key, Component* originatingComponent);

    void paint(Graphics&) override;



};