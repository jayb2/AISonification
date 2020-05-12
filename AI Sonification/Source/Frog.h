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

    int hearts;
    bool doubleJump;
    int test1;
    
    //void reset();

    Frog(int x, int y, int w, int h, Colour col);
    ~Frog();

    void paint(Graphics&);

};