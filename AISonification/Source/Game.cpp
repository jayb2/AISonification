/*
  ==============================================================================

    Game.cpp
    Created: 4 May 2020 12:53:08pm
    Author:  jayb2

  ==============================================================================
*/


#include "Game.h"


Game::Game() : m_frog(107, 810, 56, 56, Colours::green) {
    addMouseListener(this, true);
    addKeyListener(this);
    setWantsKeyboardFocus(true);

    //Handles looking for the MIDI outputs
    m_midiOutput = std::make_shared<ComboBox>("MIDI Selector");
    StringArray devices = MidiOutput::getDevices();
    m_midiOutput->addItemList(devices, 1);
    
    ///////////////////////////////////////////////////////////

    m_midiOutput->onChange = [this]() {
        String deviceName = m_midiOutput->getText();
        int DeviceID = (m_midiOutput->getSelectedId() - 1);
        DBG(deviceName);
        m_midiManager.setOutput(DeviceID);
    };

    ///////////////////////////////////////////////////////////


    addAndMakeVisible(m_midiOutput.get());

    //Sets the play button up
    m_isButtonPressed = false;
    addAndMakeVisible(m_playGame);
    m_playGame.setButtonText("Play the game!");
    m_playGame.onClick = [this] { playPressed(); };

    m_font.setSizeAndStyle(32, 1, 1, 0);

    //Adds logs to the screen
    m_logs.push_back(Log(105, 0, 60, 200, Colours::darkcyan));
    m_logs.push_back(Log(15, -500, 60, 200, Colours::darkcyan));

    //Adds fish to the screen
    m_fish.push_back(Fish(645, 0, 60, 100, Colours::darkcyan));
    m_fish.push_back(Fish(285, -314, 60, 100, Colours::darkcyan));
    m_fish.push_back(Fish(465, -627, 60, 100, Colours::darkcyan));
    m_fish.push_back(Fish(15, -940, 60, 100, Colours::darkcyan));


}

Game::~Game() {

}


void Game::update() {

    /*
    static int frogJump = 0;
    ++frogJump;
    m_frogVal = frogJump % 40;
    */

    //Processes the game as long as the play button has been pressed
    if (m_isButtonPressed) {
        m_frog.stamTick();
        
        //When frog is killed the logs and fish stop moving down the screen
        if (m_frog.alive) {
            for (int n = 0; n < m_logs.size(); ++n) {
                m_logs[n].tick(5);
            }

            for (int n = 0; n < m_fish.size(); ++n) {
                m_fish[n].tick(4);
            }
        }
       //Handles spwawning logs ---- Come back to fix this if there is time
        static int logFrame = 0;
        ++logFrame;
        m_logFrame = (logFrame / 1000);

        for (int n = 0; n < m_logs.size(); ++n) {
            if (m_frog.getShape().intersects(m_logs[n].getShape()) && m_frog.alive == true) {
                m_frog.alive = false;

                //MIDI Notes play here 
                //m_midiManager.triggerNote(1, 55, 100, 4);
                m_midiManager.setChord(-3);
               
                
                DBG("dead");

            }
        }
        //every second spawn a new log ---- Come back to fix this if there is time


        if (logFrame % 60 == 0) {

            for (int n = 0; n < m_logs.size(); ++n) {
                if (m_logs[n].isActive() == false) {
                    m_logs[n].activate();
                    break;
                }
            }
        }
    }
}

void Game::tick() {

}

void Game::setNote(int m_note) {

    //Turns note on
    //auto message = MidiMessage::noteOn(10, m_note, 1.0f);

    //Turns note off
 //   auto message = MidiMessage::noteOff(10, m_note, 1.0f);
}

void Game::playPressed()
{
    m_isButtonPressed = true;
    setEnabled(false);
    repaint();
}

void Game::mouseDown(const MouseEvent& event) {

}

bool Game::keyPressed(const KeyPress& key, Component* originatingComponent) {

    //Handles the frog movement between lily pads

    if (key.getTextCharacter() == 'd') {
        //DBG("right");
        //frogVal = 0;
        m_frog.jumpRight();
        m_frog.setImageIndex(2);


        /*if (m_frogVal < 10) {
            m_frog.setImageIndex(1);
        }
        else if (m_frogVal < 20) {
            m_frog.setImageIndex(2);
        }
        else if (m_frogVal < 30) {
            m_frog.setImageIndex(1);
        }
        else if (m_frogVal >= 30) {
            m_frog.setImageIndex(0);
        }
        DBG(m_frogVal);*/
    }

    if (key.getTextCharacter() == 'a') {
        //DBG("left");
        m_frog.jumpLeft();
        m_frog.setImageIndex(4);
    }

    //Double jumps 

    if (key.getTextCharacter() == 'e') {
        //DBG("double right");
        m_frog.doubleJumpRight();
    }

    if (key.getTextCharacter() == 'q') {
        //DBG("double left");
        m_frog.doubleJumpLeft();
    }
    return true;
}

void Game::paint(Graphics& g)
{
    g.fillAll(Colours::darkcyan);

    //Makes the grid lines for rough guidance on what the lanes are
    //May delete later on?
    g.setColour(Colours::cyan);
    for (int n = 0; n < 8; ++n)
    {
        g.drawLine((n * 90), 0, (n * 90), 920);
    }

    for (int n = 0; n < m_fish.size(); ++n) {
        m_fish[n].draw(g);
    }

    //Draws the logs
    for (int n = 0; n < m_logs.size(); ++n) {
        if (m_logs[n].isActive()) {
            m_logs[n].draw(g);
        }
    }

    //Makes the lily pads in which frog can jump on
    g.setColour(Colours::green);
    for (int n = 0; n < 8; ++n)
    {
        g.fillEllipse((n * 90) + 5, 800, 80, 80);
    }

    //Draws the frog providing it's alive
    m_frog.draw(g);
    m_frog.setImageIndex(0);
    

    //Drawing on the screen before the game starts -- will be gone when the play button is pressed
    if (!m_isButtonPressed) {
        g.fillAll(Colours::darkcyan);
        g.setColour(Colours::whitesmoke);
        g.drawRect(70, 340, 570, 260, 5);
        g.setColour(Colours::black);
        g.setFont(m_font);
        g.drawMultiLineText
        ("Avoid the incoming logs! Use the A and D keys to make your frog jump, Q and E will allow you to jump two but you'll need to let it recharge after using. Select your desired MIDI output using the drop box at the bottom", 
            110, 380, 500, 1);
    }


}

void Game::resized() {
    auto size = getLocalBounds();
    auto footer = size.removeFromBottom(20);
    m_midiOutput->setBounds(footer.removeFromLeft(100));

    //Sets size of button if it hasn't been pressed
    if (!m_isButtonPressed) {
        m_playGame.setBounds(10, 10, getWidth() - 20, 40);
    }
}


