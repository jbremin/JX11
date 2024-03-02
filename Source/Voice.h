/*
  ==============================================================================

    Voice.h
    Created: 7 Jan 2024 6:29:49pm
    Author:  Johan Bremin

  ==============================================================================
*/

#pragma once

#include "Oscillator.h"
#include "Envelope.h"

struct Voice
{
    int note;
    float saw;
    Oscillator osc1;
    Oscillator osc2;
    Envelope env;
    
    void release()
    {
        env.release();
    }
    
    void reset() {
        note = 0;
        saw = 0.0f;
        osc1.reset();
        osc2.reset();
        env.reset();
    }
    
    float render(float input) {
        float sample1 = osc1.nextSample();
        float sample2 = osc2.nextSample();
        saw = saw * 0.997f + sample1 - sample2;
        
        float output = saw + input;
        float envelope = env.nextValue();
        return output * envelope;
    }
};
