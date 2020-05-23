/*
  ==============================================================================

    StartScreen.h
    Created: 22 May 2020 11:36:40am
    Author:  jayb2

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "MidiManager.h"

class Start : public Component
{
private:
    std::shared_ptr<ComboBox> m_midiOutput;
    MidiManager m_midiManager;

public:
    bool isButtonPressed;

    TextButton playGame;

    Start();
    ~Start();

    void drawScreen(Graphics&);
    void playPressed();
    void resized() override;

};