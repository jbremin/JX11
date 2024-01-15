/*
  ==============================================================================

    Voice.h
    Created: 7 Jan 2024 6:29:49pm
    Author:  Johan Bremin

  ==============================================================================
*/

#pragma once

#include "Oscillator.h"

struct Voice {
    int note;
    Oscillator osc;
    
    void reset() {
        note = 0;
        osc.reset();
    }
    
    float render() {
        return osc.nextSample();
    }
};
