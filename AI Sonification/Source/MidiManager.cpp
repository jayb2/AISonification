/*
  ==============================================================================

    MidiManager.cpp
    Created: 19 May 2020 8:22:26pm
    Author:  jayb2

  ==============================================================================
*/

#include "MidiManager.h"

MidiManager::MidiManager() {


	startTimerHz(8);


	m_majorIntervals.push_back(0);
	m_majorIntervals.push_back(2);
	m_majorIntervals.push_back(4);
	m_majorIntervals.push_back(5);
	m_majorIntervals.push_back(7);
	m_majorIntervals.push_back(9);
	m_majorIntervals.push_back(11);

	m_chordNumber = 0;

	m_chordNotes.push_back(0);
	m_chordNotes.push_back(4);
	m_chordNotes.push_back(7);
	m_chordNotes.push_back(12);


}

void MidiManager::setOutput(int outputName) {

	m_output = MidiOutput::openDevice(outputName);

	MidiMessage testMessage = MidiMessage::noteOn(1, 60, (uint8)100);

	m_output->sendMessageNow(testMessage);

	auto currentTime = Time::getMillisecondCounter();

	Time::waitForMillisecondCounter(currentTime + 1000);

	MidiMessage endMessage = MidiMessage::noteOff(1, 60);

	m_output->sendMessageNow(endMessage);
}

void MidiManager::triggerNote(int channel, int pitch, int velocity, int numberBeats) {

	m_midiNotes.push_back(MidiInfo(channel, pitch, velocity, numberBeats));

	if (m_output != nullptr) {

		MidiMessage message = MidiMessage::noteOn(channel, pitch, (uint8)velocity);

		m_output->sendMessageNow(message);
	}

}


void MidiManager::timerCallback() {


	triggerQuantizedNote(1, 100, 16);


	std::vector<int> positions;


	for (int n = 0; n < m_midiNotes.size(); ++n) {


		if (m_midiNotes[n].numBeatsRemaining < 0) {

			if (m_output != nullptr) {
				int channel = m_midiNotes[n].channel;
				int pitch = m_midiNotes[n].pitch;
				MidiMessage message = MidiMessage::noteOff(channel, pitch);

				m_output->sendMessageNow(message);
				positions.push_back(n);
			}

		}

		m_midiNotes[n].numBeatsRemaining -= 1;


	}


	for (auto pos : positions) {
		//FIXME potential overuse of ram... 
	//	m_midiNotes.erase(m_midiNotes.begin() + pos);

	}



};



void MidiManager::triggerQuantizedNote(int channel, int velocity, int numberBeats, int lowestMidiNote, int highestMidiNote) {
	Random r;
	static std::vector<int> noteSeq = { 0,4,7,11,7,4 };
	static int pos = 0;
	//for randomness
	//int randomNote = r.nextInt(highestMidiNote) + lowestMidiNote;
	int randomNote = noteSeq[pos] + lowestMidiNote;
	++pos;
	if (pos >= noteSeq.size()) {
		pos = 0;
	}

	/* arp

	int chordInterval = m_chordNotes[randomNote % m_chordNotes.size()];
//	DBG(chordInterval);
	int index = (chordInterval + m_chordNumber) % 7;
	int octave = 48;

	while (index < 0) {
		index += 12;
		octave -= 12;
	}

	int pitch = m_majorIntervals[index % 7] + octave   ;

	*/
	//sequence
	int pitch = m_majorIntervals[randomNote % 7] + ((randomNote / 7) * 12);

	triggerNote(channel, pitch, velocity, numberBeats);

}

void MidiManager::setChord(int chordIndex) {
	m_chordNumber = chordIndex;
}
