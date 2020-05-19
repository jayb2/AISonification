/*
  ==============================================================================

	Log.cpp
	Created: 4 May 2020 12:52:29pm
	Author:  jayb2

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Log.h"

Log::Log(int x, int y, int w, int h, Colour col) :
	Shape{ x, y, w, h, col }
{

	//loadImage(ImageCache::getFromMemory(BinaryData::standing_PNG, BinaryData::standing_PNGSize));
	//loadImage(ImageCache::getFromMemory(BinaryData::jumping_PNG, BinaryData::jumping_PNGSize));

	setImageIndex(0);

}

Log::Log(const Log& other) :
	Shape(other),
	m_isActive(other.m_isActive)
{
};

Log::~Log() {

}

bool Log::isActive() {
	return m_isActive;
}
void Log::activate() {
	m_isActive = true;
}
void Log::deactivate() {
	m_isActive = false;
}

void Log::update() {

	static int frameCount = 0;

	int val = frameCount % 10;

	if (val < 5) {
		setImageIndex(0);
	}
	else {
		setImageIndex(1);
	}

	++frameCount;
};