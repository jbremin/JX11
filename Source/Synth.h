/*
  ==============================================================================

    Synth.h
    Created: 7 Jan 2024 6:29:36pm
    Author:  Johan Bremin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Voice.h"
#include "NoiseGenerator.h"

class Synth
{
public:
    Synth();
        
    void allocateResources(double sampleRate, int samplesPerBlock);
    void deallocateResources();
    void reset();
    void render(float** outputBuffers, int sampleCount);
    void midiMessage(uint8_t data0, uint8_t data1, uint8_t data2);
    
    static constexpr int MAX_VOICES = 8;
    int numVoices;
    
    float noiseMix;
    float detune;
    float tune;
    float envAttack;
    float envDecay;
    float envSustain;
    float envRelease;
    float oscMix;
        
private:
    void noteOn(int note, int velocity);
    void noteOff(int note);
    float calcPeriod(int note) const;
    void startVoice(int v, int note, int velocity);
    
    float sampleRate;
    std::array<Voice, MAX_VOICES> voices;
    NoiseGenerator noiseGen;
    
    float pitchBend;
};
