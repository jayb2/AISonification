/*
  ==============================================================================

    Frog.h
    Created: 4 May 2020 12:52:23pm
    Author:  jayb2

  ==============================================================================
*/

#pragma once
#include "Shape.h"

class Frog : public Shape {

public:

    //void reset();
    int frogScore;

    Frog(int x, int y, int w, int h, Colour col);
    ~Frog();

    void paint(Graphics&);
    void update()override;
};