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

	loadImage(ImageCache::getFromMemory(BinaryData::Log_1_png, BinaryData::Log_1_pngSize));
	loadImage(ImageCache::getFromMemory(BinaryData::Log_2_png, BinaryData::Log_2_pngSize));
	loadImage(ImageCache::getFromMemory(BinaryData::Log_3_png, BinaryData::Log_3_pngSize));

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

	int val = frameCount % 60;

	if (val < 20) {
		setImageIndex(0);
	}
	else if (val < 40) {
		setImageIndex(1);
	}
	else {
		setImageIndex(2);
	}

	++frameCount;
};