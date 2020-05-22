/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.

    //Only makes game visable if buttonPressed is true, this stops framedrop from JUCE splashscreen effecting gameplay
    addAndMakeVisible(m_start);
    if (m_start.isButtonPressed) {
        addAndMakeVisible(m_game);
    }

    setSize(720, 940);
    setFramesPerSecond(60); // This sets the frequency of the update calls.
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::update()
{
    // This function is called at the frequency specified by the setFramesPerSecond() call
    // in the constructor. You can use it to update counters, animate values, etc.
    
    //Only updates game if buttonPressed is true
    if (m_start.isButtonPressed) {
        m_game.update();
    }
}

//==============================================================================
void MainComponent::paint(Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
    
    //Draws Start screen only whilst the buttonPressed returns false
    if (!m_start.isButtonPressed) {
        m_start.drawScreen(g);
    }
    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

    m_game.setBounds(getLocalBounds());
    m_start.setBounds(getLocalBounds());

}
