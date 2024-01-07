/*
  ==============================================================================

    Voice.h
    Created: 7 Jan 2024 6:29:49pm
    Author:  Johan Bremin

  ==============================================================================
*/

#pragma once

struct Voice
{
    int note;
    int velocity;
    
    void reset()
    {
        note = 0;
        velocity = 0;
    }
};
