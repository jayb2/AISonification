/*
  ==============================================================================

    Log.h
    Created: 4 May 2020 12:52:29pm
    Author:  jayb2

  ==============================================================================
*/

#pragma once
#include "Shape.h"

class Log : public Shape {
    int m_acceleration;
    int m_numOfLogs;
    bool m_isActive = true;

public:

    Log(int x, int y, int w, int h, Colour col);
    Log(const Log& other);
    ~Log();
    bool isActive();
    void activate();
    void deactivate();
}; 