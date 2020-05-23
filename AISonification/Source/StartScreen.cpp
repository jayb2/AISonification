/*
  ==============================================================================

    StartScreen.cpp
    Created: 22 May 2020 11:36:40am
    Author:  jayb2

  ==============================================================================
*/

#include "StartScreen.h"

Start::Start() {
    isButtonPressed = false;


    m_midiOutput = std::make_shared<ComboBox>("MIDI Selector");
    StringArray devices = MidiOutput::getDevices();
    m_midiOutput->addItemList(devices, 1);
    m_midiOutput->onChange = [this]() {
        String deviceName = m_midiOutput->getText();
        int DeviceID = (m_midiOutput->getSelectedId() - 1);
        DBG(deviceName);

        m_midiManager.setOutput(DeviceID);


    };
    addAndMakeVisible(m_midiOutput.get());


    addAndMakeVisible(playGame);
    playGame.setButtonText("Play the game!");
    playGame.onClick = [this] { playPressed(); };

}

Start::~Start() {
    
}

void Start::drawScreen(Graphics& g) {
    g.fillAll(Colours::pink);

}

void Start::playPressed()
{
    isButtonPressed = true;
    repaint();
}

void Start::resized() {

    auto size = getLocalBounds();
    auto footer = size.removeFromBottom(20);
    m_midiOutput->setBounds(footer.removeFromLeft(100));

    playGame.setBounds(10, 10, getWidth() - 20, 40);

}