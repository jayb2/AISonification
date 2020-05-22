/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Game.h"
#include "StartScreen.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public AnimatedAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void update() override;

    //==============================================================================
    void paint(Graphics& g) override;

    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

    Game m_game;
    Start m_start;
    std::shared_ptr<ComboBox> m_midiOutput;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
