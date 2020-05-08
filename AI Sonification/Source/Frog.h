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
    Frog();

    bool isAlive;
    int stamina;
    int hearts;
    int doubleJump;
    
    //void reset();

};