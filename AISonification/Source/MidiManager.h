/*
  ==============================================================================

    MidiManager.h
    Created: 19 May 2020 8:22:26pm
    Author:  jayb2

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


class MidiManager : public Timer {

	std::unique_ptr<MidiOutput> m_output;


	struct MidiInfo {
		int channel, pitch, velocity, numBeatsRemaining;
		MidiInfo(int _channel, int _pitch, int _velocity, int _numBeats) :
			channel(_channel),
			pitch(_pitch),
			velocity(_velocity),
			numBeatsRemaining(_numBeats) {

		}
	};

	std::vector<MidiInfo> m_midiNotes;
	std::vector<int> m_majorIntervals;
	std::vector<int> m_chordNotes;

	int m_chordNumber;
public:
	MidiManager();

	void timerCallback()override;

	void setOutput(const String& outputName);

	void triggerNote(int channel, int pitch, int velocity, int numberBeats);

	void triggerQuantizedNote(int channel, int velocity, int numberBeats, int lowestMidiNote = 48, int highestMidiNote = 12);

	void setChord(int chordIndex);
};